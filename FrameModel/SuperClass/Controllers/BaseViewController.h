//
//  BaseViewController.h
//  FrameModel
//
//  Created by specter on 16/10/12.
//  Copyright © 2016年 specter. All rights reserved.
//    基类 - 视图控制器

#import <UIKit/UIKit.h>
#import "UIView+Ext.h"


#pragma mark -
#pragma mark 顶部导航栏Tag - BaseControllers

#define kNav_Title_ButtonTag  100010
#define kNav_Left_ButtonTag 100020   //左
#define kNav_Right_ButtonTag 100021   //右
//
#define kNav_Right_Font AdaptedFontSize(17.0)


@interface BaseViewController : UIViewController

@property (nonatomic,strong) UIColor *tingColor;

//title
- (void)setNavigationWithTitle:(NSString *)title;
- (void)setNavigationWithTitleView:(UIView *)titleView;

//left
- (void)setNavigationLeftWithStr:(NSString *)leftTitle;
- (void)setNavigationLeftWithImage:(NSString *)leftImage;
- (void)setNavigationLeftWithStr:(NSString *)leftTitle andImage:(NSString *)leftImage;

//right
- (void)setNavigationRightWithStr:(NSString *)rightTitle;
- (void)setNavigationRightWithStr:(NSString *)rightTitle andImage:(NSString *)rightImage;
- (void)setNavigationRightWithImgs:(NSArray *)images; // 字符串数组

// 点击事件
- (void)NavigationBarButtonClick:(UIButton *)sender;

/**
 *  首次加载视图(菊花)
 *
 *  @param text 加载文字
 */
- (void)ShowLoadingViewWithText:(NSString *)text;

/**
 *  加载数据
 */
- (void)ShowLoadingView;

/**
 *  关闭 加载视图(消失)
 */
- (void)DismissLoadingView;

@end
