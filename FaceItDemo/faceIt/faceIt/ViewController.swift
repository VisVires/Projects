//
//  ViewController.swift
//  faceIt
//
//  Created by William George on 7/31/17.
//  Copyright © 2017 Vis Vires. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var faceView: FaceView! {
        didSet{
            let handler = #selector(FaceView.changeScale(byReactingTo:))
            let pinchRecognizer = UIPinchGestureRecognizer(target: faceView, action: handler)
            faceView.addGestureRecognizer(pinchRecognizer)
            let tapRecognizer = UITapGestureRecognizer(target: self, action: #selector(toggleEyes(byReactingTo: )))
            tapRecognizer.numberOfTapsRequired = 1
            faceView.addGestureRecognizer(tapRecognizer)
            let swipeUpRecognizer = UISwipeGestureRecognizer(target: self, action: #selector(increaseHappiness))
            swipeUpRecognizer.direction = .Up
            faceView.addGestureRecognizer(swipeUpRecognizer)
            let swipeDownRecognizer = UISwipeGestureRecognizer(target: self, action: #selector(decreaseHappiness))
            swipeDownRecognizer.direction = .Down
            faceView.addGestureRecognizer(swipeUpRecognizer)
            updateUI()
        }
    }
    
    func toggleEyes(byReactingTo tapRecognizer: UITapGestureRecognizer) {
        if tapRecognizer.state == .Ended {
            let eyes: FacialExpression.Eyes = (expression.eyes == .closed) ? .open : .closed
            expression = FacialExpression(eyes: eyes, mouth: expression.mouth)
        }
    }
    
    var expression = FacialExpression(eyes: .closed, mouth: .frown) {
        didSet{
            updateUI()
        }
    }
    
    func increaseHappiness(){
        expression = expression.happier
    }
    func decreaseHappiness()
    {
        expression = expression.sadder
    }
    
    
    private func updateUI(){
        switch expression.eyes{
            case .open:
                faceView?.eyesOpen = true
            case .closed:
                faceView?.eyesOpen = false
            case .squinting:
                faceView?.eyesOpen = false
        }
        faceView.mouthCurv = mouthCurv[expression.mouth] ?? 0.0
    }
    
    
    private let mouthCurv = [FacialExpression.Mouth.grin:0.5, .frown:-1.0, .smile: 1.0, .neutral: 0.0, .smirk:-0.5]
}

