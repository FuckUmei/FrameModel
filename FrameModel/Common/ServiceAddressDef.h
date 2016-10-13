//
//  ServiceAddressDef.h
//  FrameModel
//
//  Created by specter on 16/10/12.
//  Copyright © 2016年 specter. All rights reserved.
//

#ifndef ServiceAddressDef_h
#define ServiceAddressDef_h

//********************************************************************************************  仓库添加
//1、商品分类添加
#define JXC_createClass  [NSString stringWithFormat:@"%@/createClass",_APPSERVER_IP]
//1、更新商品分类
#define JXC_saveClass  [NSString stringWithFormat:@"%@/saveClass",_APPSERVER_IP]
//1、商品分类列表
#define JXC_classList  [NSString stringWithFormat:@"%@/classList",_APPSERVER_IP]
//1、删除商品分类
#define JXC_delClass  [NSString stringWithFormat:@"%@/delClass",_APPSERVER_IP]

//********************************************************************************************  end

//********************************************************************************************  仓库添加
// 添加仓库
#define JXC_createHousea  [NSString stringWithFormat:@"%@/createHouse",_APPSERVER_IP]
// 更新仓库
#define JXC_saveHouse  [NSString stringWithFormat:@"%@/saveHouse",_APPSERVER_IP]
//1、仓库列表
#define JXC_houseList  [NSString stringWithFormat:@"%@/houseList",_APPSERVER_IP]
//1、删除仓库
#define JXC_delHouse  [NSString stringWithFormat:@"%@/delHouse",_APPSERVER_IP]


//********************************************************************************************  end

//********************************************************************************************   商品订单对应接口
//创建商品订单
#define JXC_createOrder  [NSString stringWithFormat:@"%@/createOrder",_APPSERVER_IP]
//、订单列表
#define JXC_orderList  [NSString stringWithFormat:@"%@/orderList",_APPSERVER_IP]
//订单详情
#define JXC_orderDetail  [NSString stringWithFormat:@"%@/orderDetail",_APPSERVER_IP]
//删除订单
#define JXC_delOrder  [NSString stringWithFormat:@"%@/delOrder",_APPSERVER_IP]


// 添加商品
#define JXC_HouseCheck  [NSString stringWithFormat:@"%@/houseCheck",_APPSERVER_IP]
//********************************************************************************************  end

//********************************************************************************************   商品订单对应接口
//1、数据统计
#define JXC_reportData  [NSString stringWithFormat:@"%@/reportData",_APPSERVER_IP]
//1、库存查询
#define JXC_houseSearch  [NSString stringWithFormat:@"%@/houseSearch",_APPSERVER_IP]


//********************************************************************************************  end

//********************************************************************************************   商品订单对应接口
// 按时间销售报表
#define JXC_sellTime  [NSString stringWithFormat:@"%@/sellTime",_APPSERVER_IP]

//销售报表 按客户
#define JXC_sellClient  [NSString stringWithFormat:@"%@/sellClient",_APPSERVER_IP]
//销售报表 按商品
#define JXC_sellGoods  [NSString stringWithFormat:@"%@/sellGoods",_APPSERVER_IP]


// ============= 【下载文件】=====
#define JXC_updateGoodsListZip [NSString stringWithFormat:@"%@/updateGoodsListZip",_APPSERVER_IP]


// =========================【店铺行业分类】===================
//1、店铺行业分类
#define JXC_tradeList [NSString stringWithFormat:@"%@/tradeList",_APPSERVER_IP]
// 新的扫码接口
#define JXC_barCodeGetGoods [NSString stringWithFormat:@"%@/barCodeGetGoods",_APPSERVER_IP]
//折线图数据
#define JXC_lineChartData [NSString stringWithFormat:@"%@/lineChartData",_APPSERVER_IP]


//=========================【app url 请求链接】=================== end

//=========================【报表路径】=================== start

//时间 销售 报表
#define JXC_sellTimeReport  [NSString stringWithFormat:@"%@/mobile/sellTimeReport/sellDayTime/token/%@",_APPSERVER_IP,[GlobalHelper getValueByUserDefault:USER_TOEKN]]
//商品 销售 报表
#define JXC_SellGoodsReport  [NSString stringWithFormat:@"%@/mobile/SellGoodsReport/index/token/%@",_APPSERVER_IP,[GlobalHelper getValueByUserDefault:USER_TOEKN]]
//客户 销售 报表
#define JXC_SellClientReport  [NSString stringWithFormat:@"%@/mobile/SellClientReport/index/token/%@",_APPSERVER_IP,[GlobalHelper getValueByUserDefault:USER_TOEKN]]
//采购 报表
#define JXC_BuyTimeReport  [NSString stringWithFormat:@"%@/mobile/BuyTimeReport/buyDayTime/token/%@",_APPSERVER_IP,[GlobalHelper getValueByUserDefault:USER_TOEKN]]

//=========================【报表路径】=================== end

//*********************个人页面的相关接口 - start*****************************************************

//获取商品数据列表
#define JXC_GoodsData  [NSString stringWithFormat:@"%@/GoodsData",_APPSERVER_IP]

//退出
#define LoginOut  [NSString stringWithFormat:@"%@/loginOut",_APPSERVER_IP]

// 删除商品数据
#define JXC_DelGoods  [NSString stringWithFormat:@"%@/delGoods",_APPSERVER_IP]

//获取商品列表
#define JXC_GoodsList  [NSString stringWithFormat:@"%@/goodsList",_APPSERVER_IP]

// 添加商品
#define JXC_CreateGoods  [NSString stringWithFormat:@"%@/createGoods",_APPSERVER_IP]

// 获取单个商品数据
#define JXC_GoodsDetail  [NSString stringWithFormat:@"%@/goodsDetail",_APPSERVER_IP]

// 修改商品
#define JXC_UpdateGoods  [NSString stringWithFormat:@"%@/updateGoods",_APPSERVER_IP]

// 商品扫码
#define JXC_CodeGetGoods  [NSString stringWithFormat:@"%@/codeGetGoods",_APPSERVER_IP]

// 同步商品列表
#define JXC_UpdateGoodsList  [NSString stringWithFormat:@"%@/updateGoodsList",_APPSERVER_IP]
//*********************个人页面的相关接口 - end*****************************************************


//*******************门店页面 - start*****************************************************************
// 门店列表
#define JXC_StoreList  [NSString stringWithFormat:@"%@/storeList",_APPSERVER_IP]
// 添加门店
#define JXC_CreateStore  [NSString stringWithFormat:@"%@/createStore",_APPSERVER_IP]

// 更新门店
#define JXC_SaveStore  [NSString stringWithFormat:@"%@/saveStore",_APPSERVER_IP]

//删除门店
#define JXC_DelStore  [NSString stringWithFormat:@"%@/delStore",_APPSERVER_IP]

// 添加门店
#define JXC_SaveShop  [NSString stringWithFormat:@"%@/saveShop",_APPSERVER_IP]


//*******************门店页面 - end*****************************************************************

//*******************权限页面 - start*****************************************************************
// 权限管理-系统权限列表
#define JXC_NodeList  [NSString stringWithFormat:@"%@/nodeList",_APPSERVER_IP]

// 权限管理-角色权限添加
#define JXC_CreateRole  [NSString stringWithFormat:@"%@/createRole",_APPSERVER_IP]

// 权限管理-角色列表
#define JXC_RoleList  [NSString stringWithFormat:@"%@/roleList",_APPSERVER_IP]

// 权限管理-角色权限详情
#define JXC_FindRole  [NSString stringWithFormat:@"%@/findRole",_APPSERVER_IP]

// 权限管理-角色权限跟新
#define JXC_SaveRole  [NSString stringWithFormat:@"%@/saveRole",_APPSERVER_IP]

// 权限管理-角色权限跟新
#define JXC_DelRole  [NSString stringWithFormat:@"%@/delRole",_APPSERVER_IP]


//*******************权限页面 - end*****************************************************************

//********************************************************************************************往来单位 - start
// 往来单位添加
#define JXC_CreateClient  [NSString stringWithFormat:@"%@/createClient",_APPSERVER_IP]

// 更新往来单位
#define JXC_SaveClient  [NSString stringWithFormat:@"%@/saveClient",_APPSERVER_IP]

// 往来单位列表
#define JXC_ClientList  [NSString stringWithFormat:@"%@/clientList",_APPSERVER_IP]

// 删除往来单位
#define JXC_DelClient  [NSString stringWithFormat:@"%@/delClient",_APPSERVER_IP]
//********************************************************************************************往来单位 - end

//********************************************************************************************商品单位 - start
// 商品单位添加
#define JXC_CreateUnit  [NSString stringWithFormat:@"%@/createUnit",_APPSERVER_IP]

// 更新商品单位
#define JXC_SaveUnit  [NSString stringWithFormat:@"%@/saveUnit",_APPSERVER_IP]

// 商品单位列表
#define JXC_UnitList  [NSString stringWithFormat:@"%@/unitList",_APPSERVER_IP]

// 删除商品单位
#define JXC_DelUnit  [NSString stringWithFormat:@"%@/delUnit",_APPSERVER_IP]
//********************************************************************************************商品单位 - end

//********************************************************************************************商品单位 - start
// 添加员工/编辑
#define JXC_CreateUser  [NSString stringWithFormat:@"%@/createUser",_APPSERVER_IP]

// 员工详情
#define JXC_FindUser  [NSString stringWithFormat:@"%@/findUser",_APPSERVER_IP]

// 员工列表
#define JXC_UserList  [NSString stringWithFormat:@"%@/userList",_APPSERVER_IP]

// 删除员工
#define JXC_DelUer  [NSString stringWithFormat:@"%@/delUser",_APPSERVER_IP]
//********************************************************************************************商品单位 - end

//*******************************************************************************  用户自定义快捷键 - start
#define JXC_definedKey  [NSString stringWithFormat:@"%@/definedKey",_APPSERVER_IP]

//*******************************************************************************  用户自定义快捷键 - end

//*******************************************************************************  主界面轮播统计- start

#define   JXC_bannerReportData  [NSString stringWithFormat:@"%@/bannerReportData",_APPSERVER_IP]

//*******************************************************************************  主界面轮播统计- end



#endif /* ServiceAddressDef_h */
