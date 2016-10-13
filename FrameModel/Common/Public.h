//
//  Public.h
//  FrameModel
//
//  Created by specter on 16/10/12.
//  Copyright © 2016年 specter. All rights reserved.
//
//#import "NSObject+MJCoding.h"

typedef void(^OKButton)();

@interface Public : NSObject
@property (nonatomic, strong) OKButton publicBlock;
/**
 *  图片裁剪
 *
 *  @param image image对象
 *  @param rect  要裁减成的尺寸
 *
 *  @return 返回裁剪之后的image对象
 */
+ (UIImage *)cutImage:(UIImage *)image frame:(CGRect)rect;

+ (CGFloat)deviceWidth:(CGFloat)width;
+ (CGFloat)deviceHeight:(CGFloat)height;
/**
 *  判断设备是 iphone几
 *
 *  @return 返回iphone型号
 */
+ (NSString *)deviceString;

/**
 *  单例
 */
+ (Public *)shared;

/// 创建左上角返回按钮
+ (UIButton *)creatBackButton;

//+ (void)setUISwitchColor:(SevenSwitch *)mySwitch;


+ (void)createNavigationLeftBarButtonItemWithCustomView:(UIButton *)myButton andNavItem:(UINavigationItem *)item;

/**
 *  后台运行
 */
//+ (void)backgroundRunning;

/**
 *  返回白色
 *
 *  @return 返回UIColor对象
 */
+ (UIColor *)returnWrightColor;

/**
 *  用于给navigation添加标题
 *
 *  @param title 标题
 *  @param color 标题颜色
 *  @param fount 文字大小
 *
 *  @return UILabel 
 */
+ (UILabel *)returnTitleView:(NSString *)title andColor:(UIColor *)color andFount:(CGFloat)fount;

/**
 *  播放声音
 */
+ (void)soundPlay:(NSString *)name;

/**
 *  震动
 */
+ (void)shakePlay;

/**
 *  获取当前时间
 *
 *  @return 返回字符串格式
 */
+ (NSString *)currentTime;

+ (NSDate *)returnDate:(NSString *)time;

+ (NSString *)returnTime:(NSString *)time;

+ (NSString *)currentTimeforData:(NSString *)strtime;
/**
 *  UIAlertView 提示框
 *
 *  @param title    标题
 *  @param message  内容
 *  @param delegate 
 */
+ (void)showAlertTitle:(NSString *)title message:(NSString *)message delegate:(id)delegate;

/**
 *  数组去重
 *
 *  @param array 输入有重复的数组
 *
 *  @return 返回按照顺序排列的没有重复的数组
 */
+ (NSMutableArray *)arrayRemoveDuplicate:(NSArray *)array;

/**
 *  控件起始高度+控件高度
 *
 *  @param widget 控件本身
 *
 *  @return 起始高度+控件考度
 */
+ (CGFloat)originAndHeight:(UIView *)widget;

/**
 *  控件起始位置+控件宽度
 *
 *  @param widget 传入控件
 *
 *  @return 返回起始位置+宽度的值
 */
+ (CGFloat)originAndWeight:(UIView *)widget;

/**
 *  毛玻璃效果
 *
 *  @param blur  0 - 1
 *  @param image 传入需要模糊的UIImage对象
 *
 *  @return 返回模糊化之后的图片
 */
+(UIImage *)gaussianBlue:(CGFloat)blur andImage:(UIImage *)image;

// build号
+ (NSString *)buildVersion;
/**
 *  NSDictionary to jsonString || 对象转json格式
 *
 *  @return 返回字符串格式
 */
+ (NSString*)DataTOjsonString:(id)object;
/**
 *  将JSON串转化为字典或者数组
 *
 *  @return 返回字符串格式
 */
+ (id)toArrayOrNSDictionary:(NSString *)jsonString;

/**
 *
 *  手机bug日志
 *
 */
+ (void)getBuglyLog;

@end
