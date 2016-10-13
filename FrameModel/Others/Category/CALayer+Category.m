//
//  CALayer+Category.h
//  xingzhengbao
//
//  Created by specter on 16/4/28.
//  Copyright © 2016年 XZB. All rights reserved.
//  类别 扩展 用于xib 按钮边框颜色

#import "CALayer+Category.h"

@implementation CALayer (Category)

- (void)setBorderColorFromUIColor:(UIColor *)color
{
    self.borderColor = color.CGColor;
}

@end
