from selenium import webdriver
import time
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC


class FacebookCrawler:

    def __init__(self, login, password):
        self.browser = webdriver.Safari(executable_path = '/usr/bin/safaridriver')
        self.wait = WebDriverWait(self.browser, 1)
        self.browser.get('https://www.facebook.com/')
        username_box = self.browser.find_element_by_id('email') 
        username_box.send_keys(login)
        password_box = self.browser.find_element_by_id('pass')
        password_box.send_keys(password) 
        login_box = self.browser.find_element_by_id('loginbutton') 
        login_box.click() 


    def _get_friends_list(self):
        return self.browser.find_elements_by_css_selector(".friendBrowserNameTitle > a")

    def get_friends(self):
        # navigate to "friends" page
        #self.browser.find_element_by_css_selector("a#findFriendsNav").click()
        self.browser.get('https://www.facebook.com/NewYorkSarbajoninDPC/')
        self.browser.find_element_by_id('like').click()

        #self.browser.find_element_by_id('friends')
        #self.browser.find_element_by_link_text('Friends').click()
        #self.browser.get('https://www.facebook.com/arghya.bhattacharya.773/friends/')
        #time.sleep(1)
        #friend_name = self.browser.find_element_by_id('fb-timeline-cover-name')
        #print(friend_name.text)

        #self.browser.get('https://www.facebook.com/events/birthdays/')
        #element = self.browser.find_elements_by_xpath("//*[@class ='enter_submit\ uiTextareaNoResize uiTextareaAutogrow uiStreamInlineTextarea\ inlineReplyTextArea mentionsTextarea textInput']")
        
        #cnt = 0
        #for el in element: 
         #   cnt += 1
        #print(str(cnt))
        # continuous scroll until no more new friends loaded
        #num_of_loaded_friends = len(self._get_friends_list())
        #while True:
        #    self.browser.execute_script("window.scrollTo(0, document.body.scrollHeight);")
        #    try:
        #        self.wait.until(lambda browser: len(self._get_friends_list()) > num_of_loaded_friends)
        #        num_of_loaded_friends = len(self._get_friends_list())
        #    except TimeoutException:
        #        break  # no more friends loaded

        #return [friend.text for friend in self._get_friends_list()]


if __name__ == '__main__':
    crawler = FacebookCrawler(login='iamarghya.1@gmail.com', password='me&swamiji@367')

    cnt = 0
    crawler.get_friends()
    #for friend in crawler.get_friends():
    #    print(friend)
    #    #cnt += 1
    #print(str(cnt))