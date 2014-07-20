//
//  QMBParallaxController.h
//  QMBParallaxScrollView-Sample
//
//  Created by Toni Möckel on 02.11.13.
//  Copyright (c) 2013 Toni Möckel. All rights reserved.
//

#import <UIKit/UIKit.h>

@class QMBParallaxController;

typedef NS_ENUM(NSUInteger, QMBParallaxState) {
    QMBParallaxStateVisible = 0,
    QMBParallaxStateFullSize = 1,
    QMBParallaxStateHidden = 2,
};

typedef NS_ENUM(NSUInteger, QMBParallaxGesture) {
    QMBParallaxGestureTopViewTap = 0,
    QMBParallaxGestureScrollsDown = 1,
    QMBParallaxGestureScrollsUp = 2,
};

@protocol QMBParallaxScrollViewControllerDelegate <NSObject>

@optional

/**
 * Callback when the user tapped the top-view 
 * sender is usually the UITapGestureRecognizer instance
 */
- (void) parallaxScrollViewController:(QMBParallaxController *) controller didChangeGesture:(QMBParallaxGesture)newGesture oldGesture:(QMBParallaxGesture)oldGesture;

/**
 * Callback when the state changed to QMBParallaxStateFullSize, QMBParallaxStateVisible or QMBParallaxStateHidden
 */
- (void) parallaxScrollViewController:(QMBParallaxController *) controller didChangeState:(QMBParallaxState) state;

/**
 * Callback when the top height changed
 */
- (void) parallaxScrollViewController:(QMBParallaxController *) controller didChangeTopHeight:(CGFloat) height;

@end



@interface QMBParallaxController : NSObject<UIGestureRecognizerDelegate>

@property (nonatomic, strong) id<QMBParallaxScrollViewControllerDelegate> delegate;

@property (nonatomic, assign, readonly) CGFloat topHeight;
@property (nonatomic, assign, setter = setFullHeight:) CGFloat fullHeight;
@property (nonatomic, assign, setter = setOverPanHeight:) CGFloat overPanHeight;

@property (nonatomic, readonly) QMBParallaxState state;

// inits
-(void)setupWithTopView:(UIView *)topView topHeight:(CGFloat)height bottomView:(UIScrollView *)bottomView;


- (void)parallaxScrollViewDidScroll:(CGPoint)contentOffset;
// configs

/**
 * Config to enable or disable top-view tap control
 * Call will be responsed by QMBParallaxScrollViewControllerDelegate instance
 */
- (void) enableTapGestureTopView:(BOOL) enable;

/**
 * Expands top view to the QMBParallaxStateFullSize state
 */
- (void)showFullTopView:(BOOL)show;

@end