//
//  Copyright (c) 2011 Brian Coyner. All rights reserved.
//

#import "BTSCoreGraphics.h"

static void BTSDrawPoint(CGContextRef context, CGPoint point)
{
    CGContextSaveGState(context);
    
    CGContextSetRGBStrokeColor(context, 0, 0, 0, 1);
    CGContextSetLineWidth(context, 5);
    CGContextSetLineCap(context, kCGLineCapRound);
    
    CGContextMoveToPoint(context, point.x, point.y);
    CGContextAddLineToPoint(context, point.x, point.y);
    CGContextStrokePath(context);
    
    CGContextRestoreGState(context);
    
}

static const float kBTSTickLength = 5.0;
static const float kAxesLength = 1000;

static void BTSDrawCoordinateAxes(CGContextRef context)
{
    CGContextSaveGState(context);
    
    CGContextBeginPath(context);
    
    // Paint the X axis green
    CGContextSetRGBStrokeColor(context, 0, 1, 0, 1);
    CGContextMoveToPoint(context, -kBTSTickLength, 0.0);
    CGContextAddLineToPoint(context, kAxesLength, 0.0);
    CGContextDrawPath(context, kCGPathStroke);
    
    // Paint the Y axis red
    CGContextSetRGBStrokeColor(context, 1, 0, 0, 1);
    CGContextMoveToPoint(context, 0.0, -kBTSTickLength);
    CGContextAddLineToPoint(context, 0.0, kAxesLength);
    CGContextDrawPath(context, kCGPathStroke);
    
    
    CGContextRestoreGState(context);
}
