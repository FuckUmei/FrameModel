//
//  AppDelegate.h
//  FrameModel
//
//  Created by specter on 16/10/12.
//  Copyright © 2016年 specter. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property float autoSizeScaleX;
@property float autoSizeScaleY;

@property (strong, nonatomic) UIWindow *window;

+ (instancetype)shareDelegate;

@end

