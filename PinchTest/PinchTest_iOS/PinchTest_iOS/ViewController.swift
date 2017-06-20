//
//  ViewController.swift
//  PinchTest_iOS
//
//  Created by William George on 6/19/17.
//  Copyright © 2017 Vis Vires. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBAction func oauthLogin(sender: UIButton, forEvent event: UIEvent) {
        
    }
	
	func signIn(signIn: GIDSignIn!, didSignInForUser user: GIDGoogleUser!,
	            withError error: NSError!) {
		if (error == nil) {
			// Perform any operations on signed in user here.
			// ...
		} else {
			print("\(error.localizedDescription)")
		}
	}}

