import sys
import httplib2
import webapp2
import os
import urllib
import urllib2
import uuid
import json
from goauthcred import GoogleOAuth
from apiclient.discovery import build
from oauth2client import tools
from oauth2client.file import Storage
from oauth2client.client import AccessTokenRefreshError
from oauth2client.client import OAuth2WebServerFlow

google_creds = GoogleOAuth()
client_id = google_creds.clientID()
client_secret = google_creds.clientSecret()
scope = google_creds.scope()
auth_end = google_creds.authEnd()
token = google_creds.token()
api = google_creds.api_key()

flow = OAuth2WebServerFlow(client_id, client_secret, scope)

storage = Storage('credentials.dat')

credentials = storage.get()