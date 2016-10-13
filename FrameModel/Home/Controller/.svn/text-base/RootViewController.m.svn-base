//
//  RootViewController.m
//  OneShopKeeper
//
//  Created by DavyZhang on 16/5/4.
//  Copyright © 2016年 yihaozhanggui. All rights reserved.
//

#import "RootViewController.h"

#import "HomeViewController.h"
#import "MeViewController.h"
#import "GMViewController.h"
#import "StatisticViewController.h"
#import "BaseNavigationController.h"

#import "HomeLineChartController.h"

#import "UIView+Borders.h"

#import <AYCheckVersion/AYCheckManager.h>


@interface RootViewController ()

@end

@implementation RootViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
}

- (CYLTabBarController *)tabBarController{
    if (_tabBarController == nil) {
//        HomeViewController *home = [[HomeViewController alloc] init];
        HomeLineChartController *home = [[HomeLineChartController alloc]init];
        UIViewController *homeNav = [[BaseNavigationController alloc]
                                     initWithRootViewController:home];
        
        GMViewController *gm = [[GMViewController alloc] init];
        UIViewController *gmNav = [[BaseNavigationController alloc]
                                       initWithRootViewController:gm];
        
        StatisticViewController *statistic = [[StatisticViewController alloc] init];
        UIViewController *statisticNav = [[BaseNavigationController alloc]
                                     initWithRootViewController:statistic];
        
        MeViewController *me = [[MeViewController alloc] init];
        UIViewController *meNav = [[BaseNavigationController alloc]
                                   initWithRootViewController:me];
        CYLTabBarController *tabBarController = [[CYLTabBarController alloc] init];
        
        // 在`-setViewControllers:`之前设置TabBar的属性，设置TabBarItem的属性，包括 title、Image、selectedImage。
        [self setUpTabBarItemsAttributesForController:tabBarController];
        
        [tabBarController setViewControllers:@[
                                               homeNav,
                                               gmNav,
                                               statisticNav,
                                               meNav
                                               ]];
        // 更多TabBar自定义设置：比如：tabBarItem 的选中和不选中文字和背景图片属性、tabbar 背景图片属性
        [[self class] customizeTabBarAppearance:tabBarController];
        [tabBarController.tabBar addTopBorderWithHeight:0.5 andColor:[UIColor hexFloatColor:@"eeeeee"]];
        _tabBarController = tabBarController;
        
    }
    return _tabBarController;
}

- (void)setUpTabBarItemsAttributesForController:(CYLTabBarController *)tabBarController {
    
    NSDictionary *dict1 = @{
                            CYLTabBarItemTitle : @"首页",
                            CYLTabBarItemImage : @"tab_home_nor",
                            CYLTabBarItemSelectedImage : @"tab_home_hl",
                            };
    NSDictionary *dict2 = @{
                            CYLTabBarItemTitle : @"货品管理",
                            CYLTabBarItemImage : @"tab_gm_nor",
                            CYLTabBarItemSelectedImage : @"tab_gm_hl",
                            };
    NSDictionary *dict3 = @{
                            CYLTabBarItemTitle : @"统计",
                            CYLTabBarItemImage : @"tab_count_nor",
                            CYLTabBarItemSelectedImage : @"tab_count_hl",
                            };
    NSDictionary *dict4 = @{
                            CYLTabBarItemTitle : @"设置",
                            CYLTabBarItemImage : @"tab_me_nor",
                            CYLTabBarItemSelectedImage : @"tab_me_hl"
                            };
    NSArray *tabBarItemsAttributes = @[
                                       dict1,
                                       dict2,
                                       dict3,
                                       dict4
                                       ];
    tabBarController.tabBarItemsAttributes = tabBarItemsAttributes;
}
/**
 *  更多TabBar自定义设置：比如：tabBarItem 的选中和不选中文字和背景图片属性、tabbar 背景图片属性
 */
+ (void)customizeTabBarAppearance:(CYLTabBarController *)tabBarController {
    
    //去除 TabBar 自带的顶部阴影
    [[UITabBar appearance] setShadowImage:[[UIImage alloc] init]];
    
    // set the text color for unselected state
    // 普通状态下的文字属性
    NSMutableDictionary *normalAttrs = [NSMutableDictionary dictionary];
    normalAttrs[NSForegroundColorAttributeName] = [UIColor colorWithRed:0.65 green:0.65 blue:0.65 alpha:1.00];
    
    // set the text color for selected state
    // 选中状态下的文字属性
    NSMutableDictionary *selectedAttrs = [NSMutableDictionary dictionary];
    selectedAttrs[NSForegroundColorAttributeName] = kapp_main_color;
    
    // set the text Attributes
    // 设置文字属性
    UITabBarItem *tabBar = [UITabBarItem appearance];
    [tabBar setTitleTextAttributes:normalAttrs forState:UIControlStateNormal];
    [tabBar setTitleTextAttributes:selectedAttrs forState:UIControlStateSelected];
    
    // Set the dark color to selected tab (the dimmed background)
    // TabBarItem选中后的背景颜色
    //    NSUInteger allItemsInTabBarCount = [CYLTabBarController allItemsInTabBarCount];
    //    [[UITabBar appearance] setSelectionIndicatorImage:[self imageFromColor:[UIColor yellowColor] forSize:CGSizeMake([UIScreen mainScreen].bounds.size.width / allItemsInTabBarCount, 49.f) withCornerRadius:0]];
    
    // set the bar background color
    // 设置背景图片
    UITabBar *tabBarAppearance = [UITabBar appearance];
    [tabBarAppearance setBackgroundImage:[UIColor imageWithColor:[UIColor whiteColor]]];
}

+ (UIImage *)imageFromColor:(UIColor *)color forSize:(CGSize)size withCornerRadius:(CGFloat)radius {
    CGRect rect = CGRectMake(0, 0, size.width, size.height);
    UIGraphicsBeginImageContext(rect.size);
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    // Begin a new image that will be the new image with the rounded corners
    // (here with the size of an UIImageView)
    UIGraphicsBeginImageContext(size);
    
    // Add a clip before drawing anything, in the shape of an rounded rect
    [[UIBezierPath bezierPathWithRoundedRect:rect cornerRadius:radius] addClip];
    // Draw your image
    [image drawInRect:rect];
    
    // Get the image, here setting the UIImageView image
    image = UIGraphicsGetImageFromCurrentImageContext();
    
    // Lets forget about that we were drawing
    UIGraphicsEndImageContext();
    return image;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
