//
//  NoticeDef.h
//  YiHaoZhuShou
//
//  Created by 张金龙 on 16/3/25.
//  Copyright © 2016年 YHZS. All rights reserved.
//   定义事件通知的名称

#ifndef NoticeDef_h
#define NoticeDef_h

//#pragma mark -
//#pragma mark 补签 同意、拒绝审批
//#define NT_SUPPLY_APPLY  @"nt_Supply_Apply"  //补签 同意、拒绝审批

#pragma mark -
#pragma mark  分类名称

#define NT_NET_STATECHANGE      @"nt_Net_StateChange"  // 网络变化监听


#pragma mark -
#pragma makr 更新个人主页头像
#define NT_UPDATE_HEADIMAGE @"nt_UPDATE_HEADIMAGE" //修改个人主页头像

#pragma mark -
#pragma makr 更新主页Item
#define NT_UPDATE_HOMEITEM @"nt_UPDATE_HomeItems" //更新主页Item


#pragma mark -
#pragma mark 获取手机验证码的通知名--登录
#define NT_GET_SMS_CODE  @"nt_get_Sms_Code"  //获取验证码完成的通知名

#pragma mark -
#pragma mark 登录完成的通知名
#define NT_LOGIN_COMPLETE  @"nt_Login_Complete"  //登录完成的通知名

#pragma mark -
#pragma mark 注册手机验证码的通知名
#define NT_CREAT_GET_SMS_CODE  @"nt_create_get_Sms_Code"  //注册手机验证码的通知名


#pragma mark -
#pragma mark 注册商铺的通知名
#define NT_JXC_CREATE_SHOP  @"nt_JXC_Creat_Shop"  //注册商铺的通知名

#pragma mark -
#pragma mark 修改个人资料的通知名Modify personal information
#define NT_JXC_MODIFY_INDOMATION  @"nt_JXC__Modify_Infomation"  //修改个人资料的通知名

#pragma mark -
#pragma mark 商品单位列表
#define NT_PRODUCT_UNITLIST  @"nt_Product_UnitList"  //商品单位列表

#pragma mark -
#pragma mark 商品单位创建
#define NT_CREATEUNIT  @"nt_CreateUnit"  //商品单位创建

#pragma mark -
#pragma mark 商品单位保存更新
#define NT_SAVEUNIT  @"nt_SaveUnit"  //商品单位保存更新

#pragma mark -
#pragma mark 商品单位删除
#define NT_DELUNIT  @"nt_DelUnit"  //商品单位删除

#pragma mark -
#pragma mark 商品单位只有一个的时候
#define NT_DELUNIT_ONLYONE  @"nt_DelUnit_onlyone"  //商品单位只有一个的时候


#pragma mark -
#pragma mark 来往单位列表
#define NT_CLIENT_LIST  @"nt_Client_List"  //来往单位列表

#pragma mark -
#pragma mark 商品单位创建
#define NT_CREATECLIENT  @"nt_CreateClient"  //来往单位创建

#pragma mark -
#pragma mark 商品单位保存更新
#define NT_SAVECLIENT  @"nt_SaveClient"  //来往单位保存更新

#pragma mark -
#pragma mark 商品单位删除
#define NT_DELCLIENT  @"nt_DelClient"  //来往单位删除


#pragma mark -
#pragma mark 扫码获取商品信息
#define NT_ScanBarCode  @"nt_ScanBarCode"  //扫码获取商品信息

//#pragma mark -
//#pragma mark 扫码获取商品信息进行盘点
//#define NT_ScanBarCodeCheck  @"nt_ScanBarCodeCheck"  // 扫码获取商品信息进行盘点

#pragma mark -
#pragma mark 扫码  -  获取条码进行搜索
#define NT_ScanSearchCode  @"nt_ScanSearchCode"  //获取条码进行搜索

#pragma mark -
#pragma mark  重置扫码界面 状态
#define NT_ReSetScanStatus  @"nt_ReSetScanStatus"  //重置扫码界面 状态

#pragma mark -
#pragma mark 扫码  -  获取条码进行搜索—— 刷新当前界面
#define NT_ScanSearchBarCodeReloadCurrent  @"nt_ScanSearchBarCodeReload"  //获取条码进行搜索

#pragma mark -
#pragma mark  扫码  -  获取条码进行搜索 - 盘点
#define NT_ScanSearchBarCodeCheck  @"nt_ScanSearchBarCodeCheck"  //获取条码进行搜索 - 盘点

#pragma mark - 
#pragma mark  添加订单扫码获取信息
#define NT_ScanSearchCodeForAddOrder  @"nt_ScanSearchCodeForAddOrder"  //获取条码进行搜索 - 盘点

#pragma mark -
#pragma mark 退出登录
#define NT_LogOut  @"nt_LogOut"  //退出登录

#pragma mark -
#pragma mark 更新主页 banner信息
#define NT_UPDATE_BANNERINFO  @"nt_UPDATE_BANNERINFO"  //更新主页 banner信息

#pragma mark -
#pragma mark 重新加载历史记录列表数据
#define NT_UPDATE_RELOADTABLE  @"nt_UPDATE_RELOADTABLE"  //更新主页 banner信息

#endif /* NoticeDef_h */
