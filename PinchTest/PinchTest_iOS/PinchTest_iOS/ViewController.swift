//
//  ViewController.swift
//  PinchTest_iOS
//
//  Created by William George on 6/20/17.
//  Copyright © 2017 Vis Vires. All rights reserved.
//

import UIKit
import GoogleSignIn

class ViewController: UIViewController , GIDSignInUIDelegate {

    @IBAction func signOutButton(sender: AnyObject) {
        GIDSignIn.sharedInstance().signOut()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        GIDSignIn.sharedInstance().uiDelegate = self
        GIDSignIn.sharedInstance().signInSilently()
        // Do any additional setup after loading the view, typically from a nib.
        if (GIDSignIn.sharedInstance().hasAuthInKeychain()){
            let storyboard = UIStoryboard(name: "Main", bundle: nil)
            let vc = storyboard.instantiateViewControllerWithIdentifier("MainView")
            self.presentViewController(vc, animated: true, completion: nil)
        }
    }
    

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

