//
//  UIImage+JL.m
//  OneShopKeeper
//
//  Created by DavyZhang on 16/8/3.
//  Copyright © 2016年 yihaozhanggui. All rights reserved.
//

#import "UIImage+JL.h"

// 使用消息机制必须 引用头文件
#import <objc/message.h>

@implementation UIImage (JL)

//加载分类到内存的时候调用
+(void)load{
    //
    Method imageNamed = class_getClassMethod(self, @selector(imageNamed:));
    Method myImageNamed = class_getClassMethod(self, @selector(jl_imageNamed:));
    
    // 交换方法的实现
    method_exchangeImplementations(imageNamed, myImageNamed);
    
}

+(instancetype)jl_imageNamed:(id)name{
    if (name==nil) {
        return [UIImage new];
    }
    // 判断图片是否为空
    UIImage *image = [self jl_imageNamed:name];
    if (image==nil) {
        NSLog(@" 图片为空 ： name - > :%@ ",name);
    }
    return  image;
}

@end
