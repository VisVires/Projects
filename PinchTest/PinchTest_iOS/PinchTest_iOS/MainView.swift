//
//  MainView.swift
//  PinchTest_iOS
//
//  Created by William George on 7/7/17.
//  Copyright © 2017 Vis Vires. All rights reserved.
//

import Foundation

import UIKit
import GoogleSignIn

class MainView: UIViewController , GIDSignInUIDelegate {
    
    var name: String?
    
    //var appDelegate = UIApplication.sharedApplication().delegate
    //var currUser : CurrentUser = appDelegate.getUserData()
    
    @IBOutlet weak var idToken: UILabel!
        
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "PinchTest"
        /*if currUser.firstName != nil{
            idToken.text = currUser.firstName
        } else {
            idToken.text = "BLEW IT"
        }*/
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

}