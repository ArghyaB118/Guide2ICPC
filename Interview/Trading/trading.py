
import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)


from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt
# Input data files are available in the read-only "../input/" directory
# For example, running this (by clicking run or pressing Shift+Enter) will list all files under the input directory
import os
filename = "input/trading_data.csv"
trades = pd.read_csv(filename, header=None)

trades.columns = ['TradeID', 'Price', 'Quantity', 'FirstID', 'LastID', 'Timestamp', 'SellBuy']
trades.sort_values(['Timestamp'], ascending=True)
(row, col) = trades.shape
print trades.head(), '\n', trades.tail()



class strategy:
  def __init__(self, bar_type, n, length):
    self.bar_type = bar_type    # time_bar, trade_count_bar,
                                # quantity_bar, quote_quantity_bar

    self.n = n                  # parameter n
    self.length = length        # total number of bars, exclude partial_bar

    self.market_trade_data = pd.DataFrame(columns=['TradeID', 'Price', 'Quantity', 'FirstID', 'LastID', 'Timestamp', 'SellBuy']) # store trade data locally
    self.bar = []               # store bar data. self.bar[0] is the oldest
                                #                 self.bar[-1] is the newest
   
    self.partial_bar = []     # keep a partial bar here

  def market_trade_event(self, trades_data):
    # Write code here to update the local bar
    if (self.bar_type == 'time_bar'):
      i = 0
      (row, col) = trades_data.shape
      for j in range(self.length):
        bar_start_time = trades_data.iloc[0]['Timestamp'] + j*self.n*1000
        bar_end_time = trades_data.iloc[0]['Timestamp'] + (j+1)*self.n*1000
        bar_length = self.n * 1000
        self.partial_bar = [bar_start_time, bar_end_time, bar_length, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]          
        while (i < row):
          if (trades_data.iloc[i]['Timestamp'] <= bar_end_time):
            trade = trades_data.iloc[i]
            self.market_trade_data = self.market_trade_data.append(trade, ignore_index=True)
            self.partial_bar[3] = self.market_trade_data.iloc[0]['Price']
            self.partial_bar[4] = self.market_trade_data.iloc[-1]['Price']
            self.partial_bar[5] = self.market_trade_data['Price'].max()
            self.partial_bar[6] = self.market_trade_data['Price'].min()
            self.partial_bar[7] = self.partial_bar[7] + 1
            self.partial_bar[8] = self.partial_bar[8] + trade['Quantity']
            self.partial_bar[9] = self.partial_bar[9] + trade['Quantity'] * trade['Price']
            self.partial_bar[10] = self.partial_bar[10] + 1 if trade['SellBuy'] == True else self.partial_bar[10]
            self.partial_bar[11] = self.partial_bar[11] + 1 if trade['SellBuy'] == False else self.partial_bar[11]
            self.partial_bar[12] = self.partial_bar[12] + trade['Quantity'] if trade['SellBuy'] == True else self.partial_bar[12]
            self.partial_bar[13] = self.partial_bar[13] + trade['Quantity'] if trade['SellBuy'] == False else self.partial_bar[13]
            self.partial_bar[14] = self.partial_bar[14] + trade['Quantity'] * trade['Price'] if trade['SellBuy'] == True else self.partial_bar[14]
            self.partial_bar[15] = self.partial_bar[15] + trade['Quantity'] * trade['Price'] if trade['SellBuy'] == False else self.partial_bar[15]
            i = i + 1
          else:
            break
        
        self.partial_bar = [0] * 16
        (bar_total_trade, col) = self.market_trade_data.shape
        self.market_trade_data['Quote_Quantity'] = self.market_trade_data['Quantity'] * self.market_trade_data['Price']
        bar_open = self.market_trade_data.iloc[0]['Price']
        bar_close = self.market_trade_data.iloc[-1]['Price']
        bar_high = self.market_trade_data['Price'].max()
        bar_low = self.market_trade_data['Price'].min()
        bar_total_quantity = self.market_trade_data['Quantity'].sum()
        bar_total_quote_quantity = self.market_trade_data['Quote_Quantity'].sum()
        bar_sell_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == True]['Quantity'].sum()
        bar_buy_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == False]['Quantity'].sum()
        bar_sell_quote_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == True]['Quote_Quantity'].sum()
        bar_buy_quote_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == False]['Quote_Quantity'].sum()
        bar_sell_trade = self.market_trade_data[self.market_trade_data['SellBuy'] == True].shape[0]
        bar_buy_trade = self.market_trade_data[self.market_trade_data['SellBuy'] == False].shape[0]
        self.market_trade_data = self.market_trade_data.iloc[0:0]
        self.bar.append([bar_start_time, bar_end_time, bar_length, bar_open, bar_close, bar_high, bar_low, bar_total_trade, bar_total_quantity, bar_total_quote_quantity, bar_sell_trade, bar_buy_trade, bar_sell_quantity, bar_buy_quantity, bar_sell_quote_quantity, bar_buy_quote_quantity])
        print self.predict(np.array([bar_end_time + 1]))
    


    elif (self.bar_type == 'trade_count_bar'):
      for j in range(self.length):
        self.partial_bar = [0] * 16
        for i in range(self.n):
          trade = trades_data.iloc[j*self.n + i]
          self.market_trade_data = self.market_trade_data.append(trade, ignore_index=True)
          self.partial_bar[0] = self.market_trade_data.iloc[0]['Timestamp']
          self.partial_bar[1] = self.market_trade_data.iloc[-1]['Timestamp']
          self.partial_bar[2] = self.partial_bar[1] - self.partial_bar[0]
          self.partial_bar[3] = self.market_trade_data.iloc[0]['Price']
          self.partial_bar[4] = self.market_trade_data.iloc[-1]['Price']
          self.partial_bar[5] = self.market_trade_data['Price'].max()
          self.partial_bar[6] = self.market_trade_data['Price'].min()
          self.partial_bar[7] = self.partial_bar[7] + 1
          self.partial_bar[8] = self.partial_bar[8] + trade['Quantity']
          self.partial_bar[9] = self.partial_bar[9] + trade['Quantity'] * trade['Price']
          self.partial_bar[10] = self.partial_bar[10] + 1 if trade['SellBuy'] == True else self.partial_bar[10]
          self.partial_bar[11] = self.partial_bar[11] + 1 if trade['SellBuy'] == False else self.partial_bar[11]
          self.partial_bar[12] = self.partial_bar[12] + trade['Quantity'] if trade['SellBuy'] == True else self.partial_bar[12]
          self.partial_bar[13] = self.partial_bar[13] + trade['Quantity'] if trade['SellBuy'] == False else self.partial_bar[13]
          self.partial_bar[14] = self.partial_bar[14] + trade['Quantity'] * trade['Price'] if trade['SellBuy'] == True else self.partial_bar[14]
          self.partial_bar[15] = self.partial_bar[15] + trade['Quantity'] * trade['Price'] if trade['SellBuy'] == False else self.partial_bar[15]
          
        self.partial_bar = [0] * 16
        bar_total_trade = self.n
        self.market_trade_data['Quote_Quantity'] = self.market_trade_data['Quantity'] * self.market_trade_data['Price']
        bar_start_time = self.market_trade_data.iloc[0]['Timestamp']
        bar_end_time = self.market_trade_data.iloc[-1]['Timestamp']
        bar_length = bar_end_time - bar_start_time
        bar_open = self.market_trade_data.iloc[0]['Price']
        bar_close = self.market_trade_data.iloc[-1]['Price']
        bar_high = self.market_trade_data['Price'].max()
        bar_low = self.market_trade_data['Price'].min()
        bar_total_quantity = self.market_trade_data['Quantity'].sum()
        bar_total_quote_quantity = self.market_trade_data['Quote_Quantity'].sum()
        bar_sell_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == True]['Quantity'].sum()
        bar_buy_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == False]['Quantity'].sum()
        bar_sell_quote_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == True]['Quote_Quantity'].sum()
        bar_buy_quote_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == False]['Quote_Quantity'].sum()
        bar_sell_trade = self.market_trade_data[self.market_trade_data['SellBuy'] == True].shape[0]
        bar_buy_trade = self.market_trade_data[self.market_trade_data['SellBuy'] == False].shape[0]
        self.market_trade_data = self.market_trade_data.iloc[0:0]
        self.bar.append([bar_start_time, bar_end_time, bar_length, bar_open, bar_close, bar_high, bar_low, bar_total_trade, bar_total_quantity, bar_total_quote_quantity, bar_sell_trade, bar_buy_trade, bar_sell_quantity, bar_buy_quantity, bar_sell_quote_quantity, bar_buy_quote_quantity])
        print self.predict(np.array([bar_end_time + 1]))
    

    elif (self.bar_type == 'quantity_bar'):
      i = 0
      (row, col) = trades_data.shape
      for j in range(self.length):
        q = 0
        self.partial_bar = [0] * 16
        while (i < row):
          if (q < self.n):
            trade = trades_data.iloc[i]
            self.market_trade_data = self.market_trade_data.append(trade, ignore_index=True)
            self.partial_bar[0] = self.market_trade_data.iloc[0]['Timestamp']
            self.partial_bar[1] = self.market_trade_data.iloc[-1]['Timestamp']
            self.partial_bar[2] = self.partial_bar[1] - self.partial_bar[0]
            self.partial_bar[3] = self.market_trade_data.iloc[0]['Price']
            self.partial_bar[4] = self.market_trade_data.iloc[-1]['Price']
            self.partial_bar[5] = self.market_trade_data['Price'].max()
            self.partial_bar[6] = self.market_trade_data['Price'].min()
            self.partial_bar[7] = self.partial_bar[7] + 1
            self.partial_bar[8] = self.partial_bar[8] + trade['Quantity']
            self.partial_bar[9] = self.partial_bar[9] + trade['Quantity'] * trade['Price']
            self.partial_bar[10] = self.partial_bar[10] + 1 if trade['SellBuy'] == True else self.partial_bar[10]
            self.partial_bar[11] = self.partial_bar[11] + 1 if trade['SellBuy'] == False else self.partial_bar[11]
            self.partial_bar[12] = self.partial_bar[12] + trade['Quantity'] if trade['SellBuy'] == True else self.partial_bar[12]
            self.partial_bar[13] = self.partial_bar[13] + trade['Quantity'] if trade['SellBuy'] == False else self.partial_bar[13]
            self.partial_bar[14] = self.partial_bar[14] + trade['Quantity'] * trade['Price'] if trade['SellBuy'] == True else self.partial_bar[14]
            self.partial_bar[15] = self.partial_bar[15] + trade['Quantity'] * trade['Price'] if trade['SellBuy'] == False else self.partial_bar[15]
            q = q + trade['Quantity']
            i = i + 1
          else:
            break

        self.partial_bar = [0] * 16    
        (bar_total_trade, col) = self.market_trade_data.shape
        self.market_trade_data['Quote_Quantity'] = self.market_trade_data['Quantity'] * self.market_trade_data['Price']
        bar_start_time = self.market_trade_data.iloc[0]['Timestamp']
        bar_end_time = self.market_trade_data.iloc[-1]['Timestamp']
        bar_length = bar_end_time - bar_start_time
        bar_open = self.market_trade_data.iloc[0]['Price']
        bar_close = self.market_trade_data.iloc[-1]['Price']
        bar_high = self.market_trade_data['Price'].max()
        bar_low = self.market_trade_data['Price'].min()
        bar_total_quantity = self.market_trade_data['Quantity'].sum()
        bar_total_quote_quantity = self.market_trade_data['Quote_Quantity'].sum()
        bar_sell_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == True]['Quantity'].sum()
        bar_buy_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == False]['Quantity'].sum()
        bar_sell_quote_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == True]['Quote_Quantity'].sum()
        bar_buy_quote_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == False]['Quote_Quantity'].sum()
        bar_sell_trade = self.market_trade_data[self.market_trade_data['SellBuy'] == True].shape[0]
        bar_buy_trade = self.market_trade_data[self.market_trade_data['SellBuy'] == False].shape[0]
        self.market_trade_data = self.market_trade_data.iloc[0:0]
        self.bar.append([bar_start_time, bar_end_time, bar_length, bar_open, bar_close, bar_high, bar_low, bar_total_trade, bar_total_quantity, bar_total_quote_quantity, bar_sell_trade, bar_buy_trade, bar_sell_quantity, bar_buy_quantity, bar_sell_quote_quantity, bar_buy_quote_quantity])
        print self.predict(np.array([bar_end_time + 1]))
    

    elif (self.bar_type == 'quote_quantity_bar'):
      i = 0
      (row, col) = trades_data.shape
      for j in range(self.length):
        self.partial_bar = [0] * 16
        q = 0
        while (i < row):
          if (q < self.n):
            trade = trades_data.iloc[i]
            self.market_trade_data = self.market_trade_data.append(trade, ignore_index=True)
            self.partial_bar[0] = self.market_trade_data.iloc[0]['Timestamp']
            self.partial_bar[1] = self.market_trade_data.iloc[-1]['Timestamp']
            self.partial_bar[2] = self.partial_bar[1] - self.partial_bar[0]
            self.partial_bar[3] = self.market_trade_data.iloc[0]['Price']
            self.partial_bar[4] = self.market_trade_data.iloc[-1]['Price']
            self.partial_bar[5] = self.market_trade_data['Price'].max()
            self.partial_bar[6] = self.market_trade_data['Price'].min()
            self.partial_bar[7] = self.partial_bar[7] + 1
            self.partial_bar[8] = self.partial_bar[8] + trade['Quantity']
            self.partial_bar[9] = self.partial_bar[9] + trade['Quantity'] * trade['Price']
            self.partial_bar[10] = self.partial_bar[10] + 1 if trade['SellBuy'] == True else self.partial_bar[10]
            self.partial_bar[11] = self.partial_bar[11] + 1 if trade['SellBuy'] == False else self.partial_bar[11]
            self.partial_bar[12] = self.partial_bar[12] + trade['Quantity'] if trade['SellBuy'] == True else self.partial_bar[12]
            self.partial_bar[13] = self.partial_bar[13] + trade['Quantity'] if trade['SellBuy'] == False else self.partial_bar[13]
            self.partial_bar[14] = self.partial_bar[14] + trade['Quantity'] * trade['Price'] if trade['SellBuy'] == True else self.partial_bar[14]
            self.partial_bar[15] = self.partial_bar[15] + trade['Quantity'] * trade['Price'] if trade['SellBuy'] == False else self.partial_bar[15]
            q = q + trade['Quantity'] * trade['Price']
            i = i + 1
          else:
            break

        self.partial_bar = [0] * 16   
        (bar_total_trade, col) = self.market_trade_data.shape
        self.market_trade_data['Quote_Quantity'] = self.market_trade_data['Quantity'] * self.market_trade_data['Price']
        bar_start_time = self.market_trade_data.iloc[0]['Timestamp']
        bar_end_time = self.market_trade_data.iloc[-1]['Timestamp']
        bar_length = bar_end_time - bar_start_time
        bar_open = self.market_trade_data.iloc[0]['Price']
        bar_close = self.market_trade_data.iloc[-1]['Price']
        bar_high = self.market_trade_data['Price'].max()
        bar_low = self.market_trade_data['Price'].min()
        bar_total_quantity = self.market_trade_data['Quantity'].sum()
        bar_total_quote_quantity = self.market_trade_data['Quote_Quantity'].sum()
        bar_sell_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == True]['Quantity'].sum()
        bar_buy_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == False]['Quantity'].sum()
        bar_sell_quote_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == True]['Quote_Quantity'].sum()
        bar_buy_quote_quantity = self.market_trade_data[self.market_trade_data['SellBuy'] == False]['Quote_Quantity'].sum()
        bar_sell_trade = self.market_trade_data[self.market_trade_data['SellBuy'] == True].shape[0]
        bar_buy_trade = self.market_trade_data[self.market_trade_data['SellBuy'] == False].shape[0]
        self.market_trade_data = self.market_trade_data.iloc[0:0]
        self.bar.append([bar_start_time, bar_end_time, bar_length, bar_open, bar_close, bar_high, bar_low, bar_total_trade, bar_total_quantity, bar_total_quote_quantity, bar_sell_trade, bar_buy_trade, bar_sell_quantity, bar_buy_quantity, bar_sell_quote_quantity, bar_buy_quote_quantity])
        print self.predict(np.array([bar_end_time + 1]))
    



  def get_bars(self, partial = False):
    return self.bar if partial is False else self.bar + self.partial_bar


  # A linear regression based predictor
  def predict(self, input_time):
    time = np.zeros(len(self.bar))
    price = np.zeros(len(self.bar))
    for i in range(len(self.bar)):
      time[i] = (self.bar[i][0] + self.bar[i][1]) / 2
      price[i] = (self.bar[i][5] + self.bar[i][6]) / 2
    model = LinearRegression().fit(time.reshape(-1, 1), price.reshape(-1, 1))
    return model.predict(input_time.reshape(-1, 1))
    



s = strategy('time_bar', 30, 10)
s.market_trade_event(trades)
print s.get_bars(True)

fig = plt.figure()
bar_data = s.get_bars(False)
X = np.arange(len(bar_data))
y = [row[4] for row in bar_data]
plt.bar(X, y, color = 'b')
plt.show()


s = strategy('trade_count_bar', 1000, 10)
s.market_trade_event(trades)
print s.get_bars(True)


fig = plt.figure()
bar_data = s.get_bars(False)
X = np.arange(len(bar_data))
y = [row[4] for row in bar_data]
plt.bar(X, y, color = 'b')
plt.show()



s = strategy('quantity_bar', 10, 10)
s.market_trade_event(trades)
print s.get_bars(True)

fig = plt.figure()
bar_data = s.get_bars(False)
X = np.arange(len(bar_data))
y = [row[4] for row in bar_data]
plt.bar(X, y, color = 'b')
plt.show()


s = strategy('quote_quantity_bar', 10000, 10)
s.market_trade_event(trades)
print s.get_bars(True)


fig = plt.figure()
bar_data = s.get_bars(False)
X = np.arange(len(bar_data))
y = [row[4] for row in bar_data]
plt.bar(X, y, color = 'b')
plt.show()
