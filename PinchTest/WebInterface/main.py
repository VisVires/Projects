from oauth2client.client import OAuth2WebServerFlow
from google.appengine.ext.webapp import template
from google.appengine.api import urlfetch
from goauthcred import GoogleOAuth
import httplib2
import logging
import traceback
import webapp2
import os
import json

CLIENT_ID = GoogleOAuth().clientID()
CLIENT_SECRET = GoogleOAuth().clientSecret()
API_KEY = GoogleOAuth().api_key()
REDIRECT_URL = GoogleOAuth().redirect()
TOKEN_URL = GoogleOAuth().token()
AUTH_URL = GoogleOAuth().authEnd()
URL = GoogleOAuth().url()


class MainPage(webapp2.RequestHandler):
	def get(self):
		flow = OAuth2WebServerFlow(
			client_id=CLIENT_ID,
			client_secret= CLIENT_SECRET,
			scope='profile',
			redirect_uri=REDIRECT_URL,
			token_uri=TOKEN_URL,
			auth_url=AUTH_URL)
		code = self.request.get("code")
		if not code:
			auth_uri = flow.step1_get_authorize_url()
			template_values = {'auth_uri': auth_uri}
			self.response.out.write((template.render('oauth.html', template_values)))
		else:
			credentials = flow.step2_exchange(code)
			http = httplib2.Http()
			http = credentials.authorize(http)
			response, content = http.request(URL, "GET")
			oauth_data = json.loads(content)
			user_id = oauth_data['id']
			body_fat_url = 'https://pinchtestweb.appspot.com/user/' + user_id
			template_values = {'url': body_fat_url}
			self.response.out.write(template.render('index.html', template_values))

class User(webapp2.RequestHandler):
	def get(self):
		self.response.out.write("This worked")



app = webapp2.WSGIApplication([
    ('/', MainPage),
    ('/user', User)
], debug=True)

'''
('/outh2callback', OAuthHandler),
('/login', LogInHandler)
'''