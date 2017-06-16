from oauth2client.client import OAuth2WebServerFlow
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
			self.response.write("""\<html><title>Crozdesk Python Example</title><body><a href="%s">Click here to login with Crozdesk.
				</a></body></html>""" % auth_uri)
		else:
			credentials = flow.step2_exchange(code)
			http = httplib2.Http()
			http = credentials.authorize(http)
			response, content = http.request(URL, "GET")
			oauth_data = json.loads(content)
			self.response.write(oauth_data['id'])


app = webapp2.WSGIApplication([
    ('/.*', MainPage)
], debug=True)

'''
('/outh2callback', OAuthHandler),
('/login', LogInHandler)

def get(self):
		google_creds = GoogleOAuth()
		client_id = google_creds.clientID()
		client_secret = google_creds.clientSecret()
		scope = google_creds.scope()
		auth_end = google_creds.authEnd()
		token = google_creds.token()
		api = google_creds.api_key()
'''