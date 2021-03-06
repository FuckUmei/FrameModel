//
//  BaseNavigationController.m
//  FrameModel
//
//  Created by specter on 16/10/12.
//  Copyright © 2016年 specter. All rights reserved.
//

#import "BaseNavigationController.h"
#import "UIImage+Helper.h"

@implementation BaseNavigationController

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController{
    if (self=[super initWithRootViewController:rootViewController]) {
        
        //按钮的颜色
        [self.navigationBar setTintColor:[UIColor whiteColor]];
        //标题颜色
        [self.navigationBar setTitleTextAttributes:@{NSForegroundColorAttributeName:[UIColor whiteColor],NSFontAttributeName:AdaptedFontSize(18)}];
        //背景颜色
        self.navigationBar.barTintColor = kapp_main_color;
        // 返回按钮图片
        [[UINavigationBar appearance] setBackIndicatorImage:[[UIImage imageNamed:@"left_return"] resize:3.0]];
        [[UINavigationBar appearance] setBackIndicatorTransitionMaskImage:[[UIImage imageNamed:@"left_return"]resize:3.0]];
//        [[UINavigationBar appearance] setBackgroundColor:kapp_main_color];
//        [[UINavigationBar appearance] setBackgroundColor:[UIColor colorWithPatternImage:[UIImage imageNamed:@"bgColor"]]];
//        [[UINavigationBar appearance] setBarStyle:UIBarStyleBlackOpaque];
       
    }
    return self;
}

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated{

    if (self.viewControllers.count > 0) {
        viewController.hidesBottomBarWhenPushed = YES;
    }
    [super pushViewController:viewController animated:animated];
}

#pragma mark - 强制横屏
//不让转屏
-(BOOL)shouldAutorotate{
    return NO;
}
-(UIInterfaceOrientation)preferredInterfaceOrientationForPresentation{
    //    return  currentOrientationState;//UIInterfaceOrientationLandscapeRight;
    if (_IsHorizontalShow) {
        return UIInterfaceOrientationLandscapeRight;
    }
    return UIInterfaceOrientationPortrait;
}

@end
