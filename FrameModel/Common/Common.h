//
//  Common.h
//  YiHaoZhuShou
//
//  Created by 张金龙 on 16/3/25.
//  Copyright © 2016年 YHZS. All rights reserved.
//
#import "Public.h"

#ifndef Common_h
#define Common_h


#define kHTTP_TIMEOUT_INTERVAL  1 // 请求超时时间
#define kUIViewAnimation_TIME  1.0 // 转场动画时间
#define kLaunchImage_TIME  1.0 //    页面停留时间
#define ktbl__NoThing_ImageName  @"NoDataImage" //   没有数据时的显示
#define ktbl__NoThing_TitleName @"暂无数据"     // 没有数据是的文字显示
#define ktbl_NoPower_TitleName @"您暂无该权限"   // 权限提示
#define kmsgShow_NotNet @"无网络连接"    // 无网络提示
#define kscanViewShowMsg @"请将条形码放入框内,即可自动扫描"
#define kdateFmat @"yyyy-MM-dd HH:mm:ss"    // 默认时间格式


// 判断版本号
#define USERINFO_BUNDLEVERSION @"CFBundleVersion"
#define APP_VERSION @"1.0.0"
#define kAPP_ID @"1147535062"


//=========================【app 尺寸/屏幕/ 适配 】===================
//获取屏幕 宽度、高度
#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

// 根据屏幕匹配高度
#define SCALEWIDTH(width)    [Public deviceWidth:width]
#define SCALEHEIGHT(height)  [Public deviceHeight:height]

//iphone4s
#define iPhone4s ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
//iphone5
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
// iphone6
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)) : NO)
// iphone6 plus
#define iPhone6plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)) : NO)
// 判断是否为iOS7
#define iOS7 ([[UIDevice currentDevice].systemVersion doubleValue] >= 7.0)
#define iOS8 ([[UIDevice currentDevice].systemVersion doubleValue] >=8.0)
#define kIS_IOS7                (kCFCoreFoundationVersionNumber > kCFCoreFoundationVersionNumber_iOS_6_1)

//不同屏幕尺寸字体适配（320，568是因为效果图为IPHONE5 如果不是则根据实际情况修改）
//iPhone4 320*480
//iPhone5 320*568
//iPhone6 375*667
//iPhone 6 Plus 414*736
//Samsung Galaxy S4 360*640
#define kScreenWidthRatio  (SCREEN_WIDTH / 375.0)
#define kScreenHeightRatio (SCREEN_HEIGHT / 667.0)
#define AdaptedWidth(x)  ceilf((x) * kScreenWidthRatio)
#define AdaptedHeight(x) ceilf((x) * kScreenHeightRatio)
#define AdaptedFontSize(R)     CHINESE_SYSTEM(AdaptedWidth(R))

//navgationBar
#define Barheight 44
#define StatusHeight 10

//=========================【app 颜色】===================
#define RGB(r,g,b)                  [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:1.f]
#define RGBA(r,g,b,a)               [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:a]
//清空背景色
#define kClearColor [UIColor clearColor]
#define kCellValue_COLOR [UIColor hexFloatColor:@"AEAEAE"]
#define kCellSelected_COLOR [UIColor hexFloatColor:@"f9f9f9"]
#define kViewController_BACK_COLOR [UIColor hexFloatColor:@"eeeeee"]

//分隔线颜色
#define klineView_Height 0.5
#define klineView_COLOR [UIColor colorWithRed:0.89 green:0.89 blue:0.89 alpha:1.00]
// 按钮颜色
#define kButton_COLOR [UIColor colorWithRed:0.11 green:0.70 blue:0.66 alpha:1.00]
//表格背景色颜色
#define kTBL_BACK_COLOR [UIColor colorWithRed:0.96 green:0.96 blue:0.96 alpha:1.00]
// 主题颜色
#define kapp_main_color [UIColor colorWithRed:0.11 green:0.70 blue:0.66 alpha:1.00]
// 标题色
#define kCellTitle_COLOR [UIColor hexFloatColor:@"545454"]
/** 调试专用随机色*/
#define kRandomColor [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]
/** 16进制颜色*/
#define RNTColor_16(c) [UIColor colorWithRed:((c>>16)&0xFF)/255.0 green:((c>>8)&0xFF)/255.0 blue:((c)&0xFF)/255.0 alpha:1.0]
/** 16进制颜色 带透明度*/
#define RNTAlphaColor_16(c, a) [UIColor colorWithRed:((c>>16)&0xFF)/255.0 green:((c>>8)&0xFF)/255.0 blue:((c)&0xFF)/255.0 alpha:a]
/** 主背景色*/
#define RNTMainColor RNTColor_16(0xffd200)
/** 按钮高亮色 */
#define RNTMainHighlightColor RNTAlphaColor_16(0xffd200, 0.5)
/** 背景颜色*/
#define RNTBackgroundColor RNTColor_16(0xeeeeee)
/** 分割线颜色*/
#define RNTSeparatorColor RNTColor_16(0xe6e6e6)
/** Mine页面Cell的text颜色*/
#define RNTCellTextColor RNTColor_16(0x19191a)

//=========================【app 字体】===================
//中文字体
#define CHINESE_FONT_NAME  @"Heiti SC"
#define CHINESE_SYSTEM(x) [UIFont fontWithName:CHINESE_FONT_NAME size:x]


// 是否空对象//
#define IS_NULL_CLASS(OBJECT) [OBJECT isKindOfClass:[NSNull class]]
#define IS_NULL_STRING(obj) ([obj isEqualToString:@""]||obj ==nil)


//=========================【app url 请求链接】=================== start
//定义URL地址
#define _APPSERVER_IP @"http://api.1zhanggui.cn"         // 开发
//#define _APPSERVER_IP @"http://dev.api.1zhanggui.cn"         // product

// 定义键盘
#define NUMBERS @"0123456789\n"//输入框必须是数字
/**
 *  随机颜色
 */
#define JLRandomColor [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1]

//=========================【app 弹窗】===================
#define ALERT_MSG(msg,btnMsg) static UIAlertView *alert; alert = [[UIAlertView alloc] initWithTitle:nil message:msg delegate:self cancelButtonTitle:btnMsg otherButtonTitles:nil, nil];\
[alert show];\

//=========================【app 日志打印】===================
// 是否上线  0:关闭     1:开启
#define IsOnline 1

#if  IsOnline
#define kerror_msg_show [error description]
#define MLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define kversion_string @"测试"
#else
#define MLog(...)
#define kerror_msg_show @"网络超时"
#define kversion_string @""
#endif


/**
 * 强弱引用转换，用于解决代码块（block）与强引用self之间的循环引用问题
 * 调用方式: `@weakify_self`实现弱引用转换，`@strongify_self`实现强引用转换
 *
 * 示例：
 * @weakify_self
 * [obj block:^{
 * @strongify_self
 * self.property = something;
 * }];
 */
#ifndef    weakify_self
#if __has_feature(objc_arc)
#define weakify_self autoreleasepool{} __weak __typeof__(self) weakSelf = self;
#else
#define weakify_self autoreleasepool{} __block __typeof__(self) blockSelf = self;
#endif
#endif
#ifndef    strongify_self
#if __has_feature(objc_arc)
#define strongify_self try{} @finally{} __typeof__(weakSelf) self = weakSelf;
#else
#define strongify_self try{} @finally{} __typeof__(blockSelf) self = blockSelf;
#endif
#endif
/**
 * 强弱引用转换，用于解决代码块（block）与强引用对象之间的循环引用问题
 * 调用方式: `@weakify(object)`实现弱引用转换，`@strongify(object)`实现强引用转换
 *
 * 示例：
 * @weakify(object)
 * [obj block:^{
 * @strongify(object)
 * strong_object = something;
 * }];
 */
#ifndef    weakify
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#endif
#ifndef    strongify
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) strong##_##object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) strong##_##object = block##_##object;
#endif
#endif


#endif /* Common_h */
