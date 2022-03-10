from selenium import webdriver 
from time import sleep 
  
#usr=input('Enter Email Id:')
usr = "iamarghya.1@gmail.com"
#pwd=input('Enter Password:')  
pwd = "me&swamiji@367"

browser = webdriver.Safari(executable_path = '/usr/bin/safaridriver')
#driver = webdriver.Chrome() 
#driver.get('https://www.facebook.com/') 
browser.get('https://www.facebook.com/')
print ("Opened facebook") 
sleep(1) 
  
username_box = browser.find_element_by_id('email') 
username_box.send_keys(usr) 
print ("Email Id entered") 
sleep(1) 
  
password_box = browser.find_element_by_id('pass') 
password_box.send_keys(pwd) 
print ("Password entered") 
  
login_box = browser.find_element_by_id('loginbutton') 
login_box.click() 
  
print ("Done") 
browser.get('https://www.facebook.com/arghya.bhattacharya.773/friends?lst=100003182125188%3A100003182125188%3A1561506972&source_ref=pb_friends_tl/')
element = browser.find_elements_by_xpath("//*[@class ='enter_submit\ uiTextareaNoResize uiTextareaAutogrow uiStreamInlineTextarea\ inlineReplyTextArea mentionsTextarea textInput']") 

cnt = 0
  
for el in element: 
    cnt += 1
print(str(cnt))
#input('Press anything to quit') 
browser.close() 
print("Finished") 