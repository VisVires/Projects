//
//  FaceView.swift
//  faceIt
//
//  Created by William George on 7/31/17.
//  Copyright © 2017 Vis Vires. All rights reserved.
//

import UIKit

class FaceView: UIView {
    
    @IBInspectable
    var scale: CGFloat = 0.9 {didSet {setNeedsDisplay()} }
    
    @IBInspectable
    var eyesOpen: Bool = true {didSet {setNeedsDisplay()} }
    
    @IBInspectable
    var mouthCurv: Double = -1.0 {didSet {setNeedsDisplay()} }//1.0 is full smile, -1.0 is full frown
    
    @IBInspectable
    var lineWidth: CGFloat = 5.0 {didSet {setNeedsDisplay()} }
    
    @IBInspectable
    var color = UIColor.blueColor()
    
    func changeScale(byReactingTo pinchRecognizer: UIPinchGestureRecognizer){
        switch pinchRecognizer.state{
            case .Changed, .Ended:
                scale *= pinchRecognizer.scale
                pinchRecognizer.scale = 1
            default:
                break
        }
    }
    
    private var skullRadius: CGFloat {
        let skullRadius = min(bounds.size.width, bounds.size.height) / 2 * scale
        return skullRadius
    }
    
    private var skullCenter: CGPoint{
        return CGPoint(x: bounds.midX, y: bounds.midY)
    }
    
    private enum Eye{
        case left
        case right
    }
    
    private func pathForEye(_ eye: Eye) -> UIBezierPath{
        
        func centerOfEye(_ eye: Eye) ->CGPoint {
            let eyeOffset = skullRadius / Ratios.skullRadiusToEyeOffset
            var eyeCenter = skullCenter
            eyeCenter.y  -= eyeOffset
            eyeCenter.x  += ((eye == .left) ? -1 : 1) * eyeOffset
            return eyeCenter
        }
        
        let eyeRadius = skullRadius/Ratios.skullRadiusToEyeRadius
        let eyeCenter = centerOfEye(eye)
        let path: UIBezierPath
        if eyesOpen{
            path = UIBezierPath(arcCenter: eyeCenter, radius: eyeRadius, startAngle: 0, endAngle: CGFloat(M_PI) * 2, clockwise: true)
        } else {
            /*path = UIBezierPath()
            let start = CGPoint(x: eyeCenter.x-eyeRadius, y: eyeCenter.y)
            let finish = CGPoint(x: eyeCenter.x - eyeRadius, y: eyeCenter.y)
            path.moveToPoint(start)
            path.addLineToPoint(finish)*/
            path = UIBezierPath(arcCenter: eyeCenter, radius: eyeRadius, startAngle: 0, endAngle: CGFloat(M_PI), clockwise: true)
        }
        path.lineWidth = lineWidth
        return path
    }
    
    private func pathForMouth() -> UIBezierPath{
        let mouthWidth = skullRadius / Ratios.skullRadiusToMouthWidth
        let mouthHeight = skullRadius / Ratios.skullRadiusToMouthHeight
        let mouthOffset = skullRadius / Ratios.skullRadiusToMouthOffset
        
        let mouthRect = CGRect(x: skullCenter.x - mouthWidth / 2,
                               y: skullCenter.y + mouthOffset,
                               width: mouthWidth,
                               height: mouthHeight)
        
        let smileOffset = CGFloat(max(-1, min(mouthCurv, 1))) * mouthRect.height
        
        let start = CGPoint(x: mouthRect.minX, y: mouthRect.midY)
        let finish = CGPoint(x: mouthRect.maxX, y: mouthRect.midY)
        
        let cp1 = CGPoint(x: start.x + mouthRect.width/3, y: start.y + smileOffset)
        let cp2 = CGPoint(x: finish.x - mouthRect.width/3, y: start.y + smileOffset)
        
        let path = UIBezierPath()
        path.moveToPoint(start)
        path.lineWidth = lineWidth
        path.addCurveToPoint(finish, controlPoint1: cp1, controlPoint2: cp2)
        return path
    
    }
    
    private func pathForSkull() -> UIBezierPath{
        let path = UIBezierPath(arcCenter: skullCenter, radius: skullRadius, startAngle: 0, endAngle: CGFloat(M_PI) * 2, clockwise: false)
        path.lineWidth = lineWidth
        return path
    }
    
    override func drawRect(rect: CGRect) {
        
        color.set()
        pathForSkull().stroke()
        pathForEye(.left).stroke()
        pathForEye(.right).stroke()
        pathForMouth().stroke()
    }
    
    private struct Ratios {
        static let skullRadiusToEyeOffset: CGFloat = 3
        static let skullRadiusToEyeRadius: CGFloat = 10
        static let skullRadiusToMouthWidth: CGFloat = 1
        static let skullRadiusToMouthHeight: CGFloat = 3
        static let skullRadiusToMouthOffset: CGFloat = 3
    }
}
