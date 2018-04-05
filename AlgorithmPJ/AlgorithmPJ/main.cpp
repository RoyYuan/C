//
//  main.cpp
//  AlgorithmPJ
//
//  Created by 袁子涵 on 15/12/28.
//  Copyright © 2015年 袁子涵. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>

#define city_path_in "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//City//in//"
#define city_path_out "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//City//out//"
#define city_path "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//City//"
#define vehicle_path "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//Vehicle//"
#define city_imf_path "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//City//cityimf.txt"
#define vehicle_imf_path "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//Vehicle//vehicleimf.txt"
#define password_path "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//admin_login"
#define help_path "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//help"
#define total_path "//Users//RoyYuan//c//C//AlgorithmPJ//AlgorithmPJ//Edge//total"
#define INF 0x3f3f3f3f

using namespace std;

//时间结构体
typedef struct {
    int hour,min;
}Time;

//交通路径结构体
typedef struct {
    string vehicle;//交通工具
    string start_place,end_place;//起始点和终点
    Time start_time,end_time;//起止时间
    long long int cost_money,cost_time;//花费金钱和时间
}Edge;

void mode_select();//模式选择
void mode_administrator();//管理员模式
void mode_passenger();//乘客模式
void mode_introduction();//系统介绍
void system_exit_print();//退出系统信息打印
void mode_select_print();//模式选择信息打印
bool administartor_login();//管理员登陆
void administrator_menu_print();//管理员模式菜单打印
void city_add();//增加城市
void edge_add();//增加路径
void city_delete();//删除城市
void edge_delete();//删除路径
void edge_recompose();//修改路径
void input_clear();//清除输入缓存
bool city_lookfor(string);//查找城市是否存在
void edge_print(Edge);//交通路径的输出
bool edge_same(Edge,Edge);//判断两条路径是否相同
bool time_compare(Time,Time);//判断两个时间的大小
bool time_compare1(Time,Time);
void edge_assign(Edge*,Edge*);//Edge的赋值
void passenger_menu_print();//乘客模式菜单打印
void city_demand_out();//城市的出发查询
void city_demand_in();//城市的抵达查询
void vehicle_demand();//交通工具信息查询
void total_demand();//交通总信息查询
void guide();//路线规划服务
int sort_cmp1(Edge,Edge);
int sort_cmp2(Edge,Edge);
int sort_cmp3(Edge,Edge);
int sort_cmp4(Edge,Edge);
int sort_cmp5(Edge,Edge);
int sort_cmp6(Edge,Edge);
int sort_cmp7(Edge,Edge);
int sort_cmp8(Edge,Edge);
void least_time_cost(string,string,Time);//最少时间花费决策方式
void least_transit(string,string,Time);//最少中转次数决策方式
void least_money_cost(string,string,Time);//最少金额花费决策方式
bool time_same(Time,Time);//判断时间是否相等
long long int time_change(Time);//转换时间

//模式选择
void mode_select()
{
    int select;
    mode_select_print();
    while(~scanf("%d",&select) && select)
    {
        switch (select) {
            case 1:
                mode_administrator();
                break;
            case 2:
                mode_passenger();
                break;
            case 3:
                mode_introduction();
                break;
            default:
                break;
        }
        mode_select_print();
    }
    system_exit_print();
}

//模式选择信息打印
void mode_select_print()
{
    system("clear");
    cout << "欢迎使用全国交通咨询系统，请选择您需要的模式。" << endl;
    cout << "1.管理员模式" << endl;
    cout << "2.乘客模式" << endl;
    cout << "3.系统介绍" << endl;
    cout << "0.退出系统" << endl;
}

//管理员模式
void mode_administrator()
{
    int select;
    //管理员登陆
    if(!administartor_login())
    {
        return;
    }
    //管理模式菜单
    administrator_menu_print();
    while (~scanf("%d",&select) && select) {
        switch (select) {
            case 1:
                city_add();
                break;
            case 2:
                edge_add();
                break;
            case 3:
                city_delete();
                break;
            case 4:
                edge_delete();
                break;
            case 5:
                edge_recompose();
                break;
            default:
                break;
        }
        administrator_menu_print();
    }
}

//增加城市
void city_add()
{
    string input,now;
    ifstream f;
    ofstream f2;
    system("clear");
    cout << "请输入您要增加的城市名:" ;
    cin >> input;
    string filename=city_path;
    filename+=input;
    f.open(filename.c_str());
    //如果不能打开输入的城市的文件，说明不存在该城市
    if (!f) {
        cout << "正在编辑信息，请稍等..." << endl;
        f2.open(filename.c_str(),ios::out);
        f2 << " " ;
        f2.close();
        filename=city_path_in;
        filename+=input;
        f2.open(filename.c_str(),ios::out);
        f2 << " " ;
        f2.close();
        filename=city_path_out;
        filename+=input;
        f2.open(filename.c_str(),ios::out);
        f2 << " " ;
        f2.close();
        f2.open(city_imf_path,ios::out|ios::app);
        f2 << input << endl;
        f2.close();
        cout << "增加城市成功！" << endl;
        getchar();
    }
    //反之能打开则已存在
    else
    {
        cout << "已存在该城市！增加失败！" << endl;
        char c;
        while ((c=getchar())!='\n' && c!=EOF);
        getchar();
    }
    f.close();
    return;
}

//增加路径
void edge_add()
{
    system("clear");
    Edge temp;
    cout << "请按提示输入您要增加路径的信息" << endl;
    cout << "请输入该路径的交通工具名" << endl;
    cin >> temp.vehicle;
    cout << "请输入该路径的起点" << endl;
    cin >> temp.start_place;
    cout << "请输入该路径的终点" << endl;
    cin >> temp.end_place;
    cout << "请输入该路径的起始时间" << endl;
    scanf("%d:%d",&temp.start_time.hour,&temp.start_time.min);
    cout << "请输入该路径的抵达时间" << endl;
    scanf("%d:%d",&temp.end_time.hour,&temp.end_time.min);
    cout << "请输入该路径花费的金额" << endl;
    cin >> temp.cost_money;
    temp.cost_time=temp.end_time.min-temp.start_time.min+(temp.end_time.hour-temp.start_time.hour)*60;
    cout << "请稍等，正在检验信息的合法性" << endl;
    //检查起点终点是否存在
    if (city_lookfor(temp.start_place)==0 || city_lookfor(temp.end_place)==0) {
        cout << "起始点信息有误！" << endl;
        return;
    }
    //检查时间是否合法
    if (temp.cost_time<0) {
        cout << "时间不合法！" << endl;
        return;
    }
    //检查消耗金钱是否合法
    if (temp.cost_money<0) {
        cout << "消耗金钱不合法！" << endl;
        return;
    }
    cout << "验证完成，正在处理。" << endl;
    //合法的话将其存入相关城市信息里
    //存到起点的out文件中
    string c=city_path_out;
    c+=temp.start_place;
    ofstream f;
    f.open(c.c_str(),ios::out|ios::app);
    f << temp.end_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    //存到终点的in文件中
    c=city_path_in;
    c+=temp.end_place;
    f.open(c.c_str(),ios::out|ios::app);
    f << temp.start_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    //存到起点的总文件中
    c=city_path;
    c+=temp.start_place;
    f.open(c.c_str(),ios::out|ios::app);
    f << temp.start_place << " ";
    f << temp.end_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    //存到终点文件的总文件中
    c=city_path;
    c+=temp.end_place;
    f.open(c.c_str(),ios::out|ios::app);
    f << temp.start_place << " ";
    f << temp.end_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    //合法的话将其存入相关交通信息里
    c=vehicle_path;
    c+=temp.vehicle;
    ifstream f1;
    ofstream f2;
    f1.open(c.c_str());
    //如果交通方式不在现有的目录中，把新交通方式增添到交通方式总信息里
    if (!f1) {
        f2.open(vehicle_imf_path,ios::out|ios::app);
        f2 << temp.vehicle << endl;
        f2.close();
    }
    f2.open(c.c_str(),ios::out|ios::app);
    f2 << temp.start_place << " ";
    f2 << temp.end_place << " ";
    f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
    f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
    f2 << temp.cost_money << " ";
    f2 << temp.cost_time << endl;
    f2.close();
    f1.close();
    //将路径加到total中
    f.open(total_path,ios::out|ios::app);
    f << temp.start_place << " ";
    f << temp.end_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
}

//删除城市
void city_delete()
{
    string input,tmp,filename;
    ifstream f1,f3;
    ofstream f2;
    Edge temp1,temp2;
    system("clear");
    cout << "请输入您要删除的城市的名称" << endl;
    cin >> input;
    if (!city_lookfor(input)) {
        cout << "您输入的城市不存在！请验证后再试。" << endl;
        return;
    }
    //将城市信息从cityimf中抹去
    f1.open(city_imf_path);
    f2.open(help_path,ios::out|ios::trunc);
    //将除了input以外的城市信息放到help里
    while (f1 >> tmp) {
        if (strcmp(tmp.c_str(), input.c_str()))
            f2 << tmp << endl;
    }
    f1.close();
    f2.close();
    //将cityimf删除，help置为cityimf
    filename=city_imf_path;
    remove(filename.c_str());
    string past=help_path;
    rename(past.c_str(), filename.c_str());
    //读取城市文件信息，删去相关文件中对应信息
    //读取out文件并删除相关信息
    filename=city_path_out;
    filename+=input;
    f1.open(filename.c_str(),ios::in);
    //依次读取out文件中出发邻接信息
    while (f1 >> temp1.end_place >> temp1.start_time.hour >> temp1.start_time.min >> temp1.end_time.hour >> temp1.end_time.min >> temp1.cost_money >> temp1.cost_time >> temp1.vehicle) {
        //在得到终点信息后，从终点城市的in文件中删去相关信息
        filename=city_path_in;
        filename+=temp1.end_place;
        f2.open(help_path,ios::out|ios::trunc);
        f3.open(filename.c_str());
        //将除了要删除的城市以外的路径信息放到help里
        while (f3 >> temp2.start_place >> temp2.start_time.hour >> temp2.start_time.min >> temp2.end_time.hour >> temp2.end_time.min >> temp2.cost_money >> temp2.cost_time >> temp2.vehicle) {
            if (strcmp(temp2.start_place.c_str(), input.c_str())) {
                f2 << temp2.start_place << " ";
                f2 << temp2.start_time.hour << " " << temp2.start_time.min << " ";
                f2 << temp2.end_time.hour << " " << temp2.end_time.min << " ";
                f2 << temp2.cost_money << " ";
                f2 << temp2.cost_time << " ";
                f2 << temp2.vehicle << endl;
            }
        }
        f2.close();
        f3.close();
        //将原文件删除，help更名
        remove(filename.c_str());
        past=help_path;
        rename(past.c_str(), filename.c_str());
        //在得到终点信息后，从终点城市的总文件中删去相关信息
        filename=city_path;
        filename+=temp1.end_place;
        f2.open(help_path,ios::out|ios::trunc);
        f3.open(filename.c_str());
        //将除了要删除的城市以外的路径信息放到help里
        while (f3 >> temp2.start_place >> temp2.end_place >> temp2.start_time.hour >> temp2.start_time.min >> temp2.end_time.hour >> temp2.end_time.min >> temp2.cost_money >> temp2.cost_time >> temp2.vehicle) {
            if (strcmp(temp2.start_place.c_str(), input.c_str())) {
                f2 << temp2.start_place << " ";
                f2 << temp2.end_place << " ";
                f2 << temp2.start_time.hour << " " << temp2.start_time.min << " ";
                f2 << temp2.end_time.hour << " " << temp2.end_time.min << " ";
                f2 << temp2.cost_money << " ";
                f2 << temp2.cost_time << " ";
                f2 << temp2.vehicle << endl;
            }
        }
        f2.close();
        f3.close();
        //将原文件删除，help更名
        remove(filename.c_str());
        past=help_path;
        rename(past.c_str(), filename.c_str());
    }
    f1.close();
    //处理完out文件后将其删除
    filename=city_path_out;
    filename+=input;
    remove(filename.c_str());
    //读取in文件中相关信息并进行处理
    filename=city_path_in;
    filename+=input;
    f1.open(filename.c_str(),ios::in);
    while (f1 >> temp1.start_place >> temp1.start_time.hour >> temp1.start_time.min >> temp1.end_time.hour >> temp1.end_time.min >> temp1.cost_money >> temp1.cost_time >> temp1.vehicle) {
        //在得到起点信息后，从起点城市的out文件中删去相关信息
        filename=city_path_out;
        filename+=temp1.start_place;
        f2.open(help_path,ios::out|ios::trunc);
        f3.open(filename.c_str());
        //将除了要删除的城市以外的路径信息放到help里
        while (f3 >> temp2.end_place >> temp2.start_time.hour >> temp2.start_time.min >> temp2.end_time.hour >> temp2.end_time.min >> temp2.cost_money >> temp2.cost_time >> temp2.vehicle) {
            if (strcmp(temp2.end_place.c_str(), input.c_str())) {
                f2 << temp2.end_place << " ";
                f2 << temp2.start_time.hour << " " << temp2.start_time.min << " ";
                f2 << temp2.end_time.hour << " " << temp2.end_time.min << " ";
                f2 << temp2.cost_money << " ";
                f2 << temp2.cost_time << " ";
                f2 << temp2.vehicle << endl;
            }
        }
        f2.close();
        f3.close();
        //将原文件删除，help更名
        remove(filename.c_str());
        past=help_path;
        rename(past.c_str(), filename.c_str());
        //在得到起点信息后，从起点城市的总文件中删去相关信息
        filename=city_path;
        filename+=temp1.start_place;
        f2.open(help_path,ios::out|ios::trunc);
        f3.open(filename.c_str());
        //将除了要删除的城市以外的路径信息放到help里
        while (f3 >> temp2.start_place >> temp2.end_place >> temp2.start_time.hour >> temp2.start_time.min >> temp2.end_time.hour >> temp2.end_time.min >> temp2.cost_money >> temp2.cost_time >> temp2.vehicle) {
            if (strcmp(temp2.end_place.c_str(), input.c_str())) {
                f2 << temp2.start_place << " ";
                f2 << temp2.end_place << " ";
                f2 << temp2.start_time.hour << " " << temp2.start_time.min << " ";
                f2 << temp2.end_time.hour << " " << temp2.end_time.min << " ";
                f2 << temp2.cost_money << " ";
                f2 << temp2.cost_time << " ";
                f2 << temp2.vehicle << endl;
            }
        }
        f2.close();
        f3.close();
        //将原文件删除，help更名
        remove(filename.c_str());
        past=help_path;
        rename(past.c_str(), filename.c_str());
    }
    f1.close();
    //处理完in文件后将其删除
    filename=city_path_in;
    filename+=input;
    remove(filename.c_str());
    //从主文件中读取信息，将vehicle中数据删去
    filename=city_path;
    filename+=input;
    f1.open(filename.c_str(),ios::in);
    while (f1 >> temp1.start_place >> temp1.end_place >> temp1.start_time.hour >> temp1.start_time.min >> temp1.end_time.hour >> temp1.end_time.min >> temp1.cost_money >> temp1.cost_time >> temp1.vehicle) {
        //得到交通方式信息后处理相关文件
        long long int left=0;
        string vehicle=vehicle_path;
        vehicle+=temp1.vehicle;
        f2.open(help_path,ios::out|ios::trunc);
        f3.open(vehicle.c_str(),ios::in);
        //将除了要删除的城市以外的路径信息放到help里
        while (f3 >> temp2.start_place >> temp2.end_place >> temp2.start_time.hour >> temp2.start_time.min >> temp2.end_time.hour >> temp2.end_time.min >> temp2.cost_money >> temp2.cost_time) {
            if (strcmp(temp2.start_place.c_str(), input.c_str()) && strcmp(temp2.end_place.c_str(), input.c_str())) {
                f2 << temp2.start_place << " ";
                f2 << temp2.end_place << " ";
                f2 << temp2.start_time.hour << " " << temp2.start_time.min << " ";
                f2 << temp2.end_time.hour << " " << temp2.end_time.min << " ";
                f2 << temp2.cost_money << " ";
                f2 << temp2.cost_time << endl;
                left++;
            }
        }
        f2.close();
        f3.close();
        //将原文件删除，help更名
        remove(vehicle.c_str());
        past=help_path;
        rename(past.c_str(), vehicle.c_str());
        //如果该交通方式已不再有其他路径，就从总交通方式中删去
        if (left==0) {
            f2.open(help_path,ios::out|ios::trunc);
            f3.open(vehicle_imf_path,ios::in);
            remove(vehicle.c_str());
            while (f3 >> temp2.vehicle) {
                if (strcmp(temp2.vehicle.c_str(), temp1.vehicle.c_str())) {
                    f2 << temp2.vehicle << endl;
                }
            }
            f2.close();
            f3.close();
            //将原文件删除，help更名
            string fn;
            fn=vehicle_imf_path;
            past=help_path;
            remove(fn.c_str());
            rename(past.c_str(), fn.c_str());
        }
    }
    f1.close();
    //从总文件中读取信息，删去total中相关信息
    filename=city_path;
    filename+=input;
    f1.open(filename.c_str());
    while (f1 >> temp1.start_place >> temp1.end_place >> temp1.start_time.hour >> temp1.start_time.min >> temp1.end_time.hour >> temp1.end_time.min >> temp1.cost_money >> temp1.cost_time >> temp1.vehicle) {
        //得到交通方式信息后处理相关文件
        f2.open(help_path,ios::out|ios::trunc);
        f3.open(total_path,ios::in);
        //将除了要删除的城市以外的路径信息放到help里
        while (f3 >> temp2.start_place >> temp2.end_place >> temp2.start_time.hour >> temp2.start_time.min >> temp2.end_time.hour >> temp2.end_time.min >> temp2.cost_money >> temp2.cost_time) {
            if (strcmp(temp2.start_place.c_str(), input.c_str()) && strcmp(temp2.end_place.c_str(), input.c_str())) {
                f2 << temp2.start_place << " ";
                f2 << temp2.end_place << " ";
                f2 << temp2.start_time.hour << " " << temp2.start_time.min << " ";
                f2 << temp2.end_time.hour << " " << temp2.end_time.min << " ";
                f2 << temp2.cost_money << " ";
                f2 << temp2.cost_time << endl;
                f2 << temp2.vehicle;
            }
        }
        f2.close();
        f3.close();
        //将原文件删除，help更名
        string fn=total_path;
        remove(fn.c_str());
        past=help_path;
        rename(past.c_str(), fn.c_str());
    }
    f1.close();
    //将城市文件最后删去
    filename=city_path;
    filename+=input;
    remove(filename.c_str());
}

//删除路径
void edge_delete()
{
    vector<Edge>V;
    V.clear();
    Edge input,temp;
    int total=0;
    string filename,past;
    ifstream f1,f3;
    ofstream f2;
    system("clear");
    cout << "请输入您要删除的路径的起点" << endl;
    cin >> input.start_place;
    cout << "请输入您要删除的路径的终点" << endl;
    cin >> input.end_place;
    cout << "请输入您要删除的路径的交通方式" << endl;
    cin >> input.vehicle;
    filename=vehicle_path;
    filename+=input.vehicle;
    f1.open(filename.c_str(),ios::in);
    if (!f1) {
        cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
        return;
    }
    //进行一定程度的模糊查找，符合标准的都放到vector里
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time) {
        if (temp.start_place==input.start_place && temp.end_place==input.end_place) {
            if (total==0) {
                cout << "找到以下符合条件的信息" << endl;
            }
            total++;
            temp.vehicle=input.vehicle;
            edge_print(temp);
            V.push_back(temp);
        }
    }
    f1.close();
    if (total<1) {
        cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
        return;
    }
    if (total>1) {
        cout << "请进一步精确信息" << endl;
        cout << "请输入要删除的路径的出发时间的小时位" << endl;
        scanf("%d",&input.start_time.hour);
        for (int i=0; i<V.size(); i++) {
            if (input.start_time.hour!=V[i].start_time.hour) {
                vector<Edge>::iterator it = V.begin()+i;
                V.erase(it);
                total--;
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
        if (total>1) {
            cout << "找到以下符合条件的信息" << endl;
            for (int i=0; i<V.size(); i++) {
                edge_print(V[i]);
            }
            cout << "请进一步精确信息" << endl;
            cout << "请输入要删除的路径的抵达时间的小时位" << endl;
            scanf("%d",&input.end_time.hour);
            for (int i=0; i<V.size(); i++) {
                if (input.end_time.hour!=V[i].end_time.hour) {
                    vector<Edge>::iterator it=V.begin()+i;
                    V.erase(it);
                    total--;
                }
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
        if (total>1) {
            cout << "找到以下符合条件的信息" << endl;
            for (int i=0; i<V.size(); i++) {
                edge_print(V[i]);
            }
            cout << "请进一步精确信息" << endl;
            cout << "请输入要删除的路径的花费金额" << endl;
            cin >> temp.cost_money;
            for (int i=0; i<V.size(); i++) {
                if (input.cost_money!=V[i].cost_money) {
                    vector<Edge>::iterator it=V.begin()+i;
                    V.erase(it);
                    total--;
                }
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
        if (total>1) {
            cout << "找到以下符合条件的信息" << endl;
            for (int i=0; i<V.size(); i++) {
                edge_print(V[i]);
            }
            cout << "请进一步精确信息" << endl;
            cout << "请输入要删除的路径的出发时间的分钟位" << endl;
            cin >> temp.start_time.min;
            for (int i=0; i<V.size(); i++) {
                if (input.start_time.min!=V[i].start_time.min) {
                    vector<Edge>::iterator it=V.begin()+i;
                    V.erase(it);
                    total--;
                }
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
        if (total >1) {
            cout << "找到以下符合条件的信息" << endl;
            for (int i=0; i<V.size(); i++) {
                edge_print(V[i]);
            }
            cout << "请进一步精确信息" << endl;
            cout << "请输入要删除的路径的抵达时间的分钟位" << endl;
            cin >> temp.end_time.min;
            for (int i=0; i<V.size(); i++) {
                if (input.end_time.min!=V[i].end_time.min) {
                    vector<Edge>::iterator it=V.begin()+i;
                    V.erase(it);
                    total--;
                }
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
    }
    //在模糊查找后定位于vector里的第一个
    V[0].vehicle=input.vehicle;
    edge_assign(&input, &V[0]);
    char choose;
    cout << "确定删除以下这条路径么?(Y/N)" << endl;
    edge_print(input);
    cin >> choose;
    if (choose != 'y'  && choose != 'Y') {
        return;
    }
    //从vehicle中删去这条路径
    int left=0;
    filename=vehicle_path;
    filename+=input.vehicle;
    f1.open(filename.c_str(),ios::in);
    f2.open(help_path,ios::out|ios::trunc);
    temp.vehicle=input.vehicle;
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << endl;
            left++;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //如果该交通方式已不再有其他路径，就从总交通方式中删去
    if (left==0) {
        f2.open(help_path,ios::out|ios::trunc);
        f1.open(vehicle_imf_path,ios::in);
        remove(input.vehicle.c_str());
        while (f1 >> temp.vehicle) {
            if (strcmp(temp.vehicle.c_str(), input.vehicle.c_str())) {
                f2 << temp.vehicle << endl;
            }
        }
        f1.close();
        f2.close();
        //将原文件删除，help更名
        string fn;
        fn=vehicle_imf_path;
        past=help_path;
        remove(fn.c_str());
        rename(past.c_str(), fn.c_str());
    }
    //从起点的out中删去这条路径
    filename=city_path_out;
    filename+=input.start_place;
    f1.open(filename.c_str());
    f2.open(help_path,ios::out|ios::trunc);
    temp.start_place=input.start_place;
    while (f1 >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //从终点的in中删去这条路径
    filename=city_path_in;
    filename+=input.end_place;
    f1.open(filename.c_str());
    f2.open(help_path,ios::out|ios::trunc);
    temp.end_place=input.end_place;
    while (f1 >> temp.start_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //从起点的总信息中删去这条路径
    filename=city_path;
    filename+=input.start_place;
    f1.open(filename.c_str());
    f2.open(help_path,ios::out|ios::trunc);
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //从终点的总信息中删去这条路径
    filename=city_path;
    filename+=input.end_place;
    f1.open(filename.c_str());
    f2.open(help_path,ios::out|ios::trunc);
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //从total中删去这条路径
    f1.open(total_path);
    f2.open(help_path,ios::out|ios::trunc);
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    filename=total_path;
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    return;
}

//修改路径
void edge_recompose()
{
    vector<Edge>V;
    V.clear();
    Edge input,temp,temp1,temp2,temp3;
    int total=0,op;
    string filename,past;
    ifstream f1,f3;
    ofstream f2;
    system("clear");
    cout << "请输入您要修改的路径的起点" << endl;
    cin >> input.start_place;
    cout << "请输入您要修改的路径的终点" << endl;
    cin >> input.end_place;
    cout << "请输入您要修改的路径的交通方式" << endl;
    cin >> input.vehicle;
    filename=vehicle_path;
    filename+=input.vehicle;
    f1.open(filename.c_str(),ios::in);
    if (!f1) {
        cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
        return;
    }
    //进行一定程度的模糊查找，符合标准的都放到vector里
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time) {
        if (temp.start_place==input.start_place && temp.end_place==input.end_place) {
            if (total==0) {
                cout << "找到以下符合条件的信息" << endl;
            }
            total++;
            temp.vehicle=input.vehicle;
            edge_print(temp);
            V.push_back(temp);
        }
    }
    f1.close();
    if (total<1) {
        cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
        return;
    }
    if (total>1) {
        cout << "请进一步精确信息" << endl;
        cout << "请输入要修改的路径的出发时间的小时位" << endl;
        scanf("%d",&input.start_time.hour);
        for (int i=0; i<V.size(); i++) {
            if (input.start_time.hour!=V[i].start_time.hour) {
                vector<Edge>::iterator it = V.begin()+i;
                V.erase(it);
                total--;
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
        if (total>1) {
            cout << "找到以下符合条件的信息" << endl;
            for (int i=0; i<V.size(); i++) {
                edge_print(V[i]);
            }
            cout << "请进一步精确信息" << endl;
            cout << "请输入要修改的路径的抵达时间的小时位" << endl;
            scanf("%d",&input.end_time.hour);
            for (int i=0; i<V.size(); i++) {
                if (input.end_time.hour!=V[i].end_time.hour) {
                    vector<Edge>::iterator it=V.begin()+i;
                    V.erase(it);
                    total--;
                }
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
        if (total>1) {
            cout << "找到以下符合条件的信息" << endl;
            for (int i=0; i<V.size(); i++) {
                edge_print(V[i]);
            }
            cout << "请进一步精确信息" << endl;
            cout << "请输入要修改的路径的花费金额" << endl;
            cin >> temp.cost_money;
            for (int i=0; i<V.size(); i++) {
                if (input.cost_money!=V[i].cost_money) {
                    vector<Edge>::iterator it=V.begin()+i;
                    V.erase(it);
                    total--;
                }
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
        if (total>1) {
            cout << "找到以下符合条件的信息" << endl;
            for (int i=0; i<V.size(); i++) {
                edge_print(V[i]);
            }
            cout << "请进一步精确信息" << endl;
            cout << "请输入要修改的路径的出发时间的分钟位" << endl;
            cin >> temp.start_time.min;
            for (int i=0; i<V.size(); i++) {
                if (input.start_time.min!=V[i].start_time.min) {
                    vector<Edge>::iterator it=V.begin()+i;
                    V.erase(it);
                    total--;
                }
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
        if (total >1) {
            cout << "找到以下符合条件的信息" << endl;
            for (int i=0; i<V.size(); i++) {
                edge_print(V[i]);
            }
            cout << "请进一步精确信息" << endl;
            cout << "请输入要修改的路径的抵达时间的分钟位" << endl;
            cin >> temp.end_time.min;
            for (int i=0; i<V.size(); i++) {
                if (input.end_time.min!=V[i].end_time.min) {
                    vector<Edge>::iterator it=V.begin()+i;
                    V.erase(it);
                    total--;
                }
            }
        }
        if (total<1) {
            cout << "所输入的信息有误，无法查找到符合条件的路径" << endl;
            return;
        }
    }
    //在模糊查找后定位于vector里的第一个
    V[0].vehicle=input.vehicle;
    edge_assign(&input, &V[0]);
    char choose;
    cout << "确定修改以下这条路径么?(Y/N)" << endl;
    edge_print(input);
    cin >> choose;
    if (choose != 'y'  && choose != 'Y') {
        return;
    }
    //先删除这条路径的信息
    //从vehicle中删去这条路径
    int left=0;
    filename=vehicle_path;
    filename+=input.vehicle;
    f1.open(filename.c_str(),ios::in);
    f2.open(help_path,ios::out|ios::trunc);
    temp.vehicle=input.vehicle;
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << endl;
            left++;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //如果该交通方式已不再有其他路径，就从总交通方式中删去
    if (left==0) {
        f2.open(help_path,ios::out|ios::trunc);
        f1.open(vehicle_imf_path,ios::in);
        remove(input.vehicle.c_str());
        while (f1 >> temp.vehicle) {
            if (strcmp(temp.vehicle.c_str(), input.vehicle.c_str())) {
                f2 << temp.vehicle << endl;
            }
        }
        f1.close();
        f2.close();
        //将原文件删除，help更名
        string fn;
        fn=vehicle_imf_path;
        past=help_path;
        remove(fn.c_str());
        rename(past.c_str(), fn.c_str());
    }
    
    //从起点的out中删去这条路径
    filename=city_path_out;
    filename+=input.start_place;
    f1.open(filename.c_str());
    f2.open(help_path,ios::out|ios::trunc);
    temp.start_place=input.start_place;
    while (f1 >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //从终点的in中删去这条路径
    filename=city_path_in;
    filename+=input.end_place;
    f1.open(filename.c_str());
    f2.open(help_path,ios::out|ios::trunc);
    temp.end_place=input.end_place;
    while (f1 >> temp.start_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //从起点的总信息中删去这条路径
    filename=city_path;
    filename+=input.start_place;
    f1.open(filename.c_str());
    f2.open(help_path,ios::out|ios::trunc);
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //从终点的总信息中删去这条路径
    filename=city_path;
    filename+=input.end_place;
    f1.open(filename.c_str());
    f2.open(help_path,ios::out|ios::trunc);
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //从total中删去这条路径
    f1.open(total_path);
    f2.open(help_path,ios::out|ios::trunc);
    while (f1 >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        if (!edge_same(temp, input)) {
            f2 << temp.start_place << " ";
            f2 << temp.end_place << " ";
            f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
            f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
            f2 << temp.cost_money << " ";
            f2 << temp.cost_time << " ";
            f2 << temp.vehicle << endl;
        }
    }
    f1.close();
    f2.close();
    //将原文件删除，help更名
    filename=total_path;
    remove(filename.c_str());
    past=help_path;
    rename(past.c_str(), filename.c_str());
    //更新修改后内容
    edge_assign(&temp, &input);
    while (1) {
        system("clear");
        cout << "当前信息为：" << endl;
        edge_print(temp);
        cout << "请选择您要修改的内容" << endl;
        cout << "1.出发地点" << endl;
        cout << "2.抵达地点" << endl;
        cout << "3.出发时间" << endl;
        cout << "4.抵达时间" << endl;
        cout << "5.花费金钱" << endl;
        cout << "6.交通工具" << endl;
        cout << "0.退出修改" << endl;
        cin >> op;
        switch (op) {
            case 1:
                cout << "请输入新的出发地点" << endl;
                cin >> temp.start_place;
                break;
            case 2:
                cout << "请输入新的抵达地点" << endl;
                cin >> temp.end_place;
                break;
            case 3:
                cout << "请输入新的出发时间" << endl;
                scanf("%d:%d",&temp.start_time.hour,&temp.start_time.min);
                break;
            case 4:
                cout << "请输入新的抵达时间" << endl;
                scanf("%d:%d",&temp.end_time.hour,&temp.end_time.min);
                break;
            case 5:
                cout << "请输入新的花费金钱" << endl;
                cin >> temp.cost_money;
                break;
            case 6:
                cout << "请输入新的交通工具" << endl;
                break;
            default:
                break;
        }
        if (op==0) {
            break;
        }
        else
        {
            cout << "请问还要继续修改其他信息么？（Y/N)" << endl;
            cin >> choose;
            if (choose!='y' && choose!='Y') {
                break;
            }
        }
    }
    cout << "保存修改中，请稍候" << endl;
    //将temp这个edge加到文件中
    //检查起点终点是否存在
    if (city_lookfor(temp.start_place)==0 || city_lookfor(temp.end_place)==0) {
        cout << "起始点信息有误！" << endl;
        return;
    }
    //检查时间是否合法
    if (temp.cost_time<0) {
        cout << "时间不合法！" << endl;
        return;
    }
    //检查消耗金钱是否合法
    if (temp.cost_money<0) {
        cout << "消耗金钱不合法！" << endl;
        return;
    }
    cout << "验证完成，正在处理。" << endl;
    //合法的话将其存入相关城市信息里
    //存到起点的out文件中
    string c=city_path_out;
    c+=temp.start_place;
    ofstream f;
    f.open(c.c_str(),ios::out|ios::app);
    f << temp.end_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    //存到终点的in文件中
    c=city_path_in;
    c+=temp.end_place;
    f.open(c.c_str(),ios::out|ios::app);
    f << temp.start_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    //存到起点的总文件中
    c=city_path;
    c+=temp.start_place;
    f.open(c.c_str(),ios::out|ios::app);
    f << temp.start_place << " ";
    f << temp.end_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    //存到终点文件的总文件中
    c=city_path;
    c+=temp.end_place;
    f.open(c.c_str(),ios::out|ios::app);
    f << temp.start_place << " ";
    f << temp.end_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    //合法的话将其存入相关交通信息里
    c=vehicle_path;
    c+=temp.vehicle;
    f1.open(c.c_str());
    //如果交通方式不在现有的目录中，把新交通方式增添到交通方式总信息里
    if (!f1) {
        f2.open(vehicle_imf_path,ios::out|ios::app);
        f2 << temp.vehicle << endl;
        f2.close();
    }
    f2.open(c.c_str(),ios::out|ios::app);
    f2 << temp.start_place << " ";
    f2 << temp.end_place << " ";
    f2 << temp.start_time.hour << " " << temp.start_time.min << " ";
    f2 << temp.end_time.hour << " " << temp.end_time.min << " ";
    f2 << temp.cost_money << " ";
    f2 << temp.cost_time << endl;
    f2.close();
    f1.close();
    //将路径加到total中
    f.open(total_path,ios::out|ios::app);
    f << temp.start_place << " ";
    f << temp.end_place << " ";
    f << temp.start_time.hour << " " << temp.start_time.min << " ";
    f << temp.end_time.hour << " " << temp.end_time.min << " ";
    f << temp.cost_money << " ";
    f << temp.cost_time << " ";
    f << temp.vehicle << endl;
    f.close();
    cout << "保存成功！"  << endl;
    char b;
    while ((b=getchar())!='\n' && b!=EOF);
    getchar();
}

//乘客模式
void mode_passenger()
{
    int select;
    passenger_menu_print();
    while (~scanf("%d",&select) && select) {
        switch (select) {
            case 1:
                city_demand_out();
                break;
            case 2:
                city_demand_in();
                break;
            case 3:
                vehicle_demand();
                break;
            case 4:
                total_demand();
                break;
            case 5:
                guide();
                break;
            default:
                break;
        }
        passenger_menu_print();
    }
}

//系统介绍
void mode_introduction()
{
    system("clear");
    cout << "欢迎使用全国交通系统，本系统为用户提供了两种使用模式:" << endl;
    cout << "1.管理员模式：用户只需输入正确密码即可进入此模式，在此模式中，用户可对交通网络信息进行编辑修改。" << endl;
    cout << "2.乘客模式：所有用户都可以进入此模式，在此模式中，用户可查询具体城市的进出路线信息，以及总体信息的查询（系统为用户提供了9种浏览排序），用户还可根据自己的需求，输入出发城市以及目标城市，提供了三种决策方案来进行guide的提供。" << endl;
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
    getchar();
}

//退出系统信息打印
void system_exit_print()
{
    system("clear");
    cout << "感谢您的支持！\n系统正在退出，欢迎再次使用!" << endl;
}

//管理员登陆
bool administartor_login()
{
    system("clear");
    ifstream f;
    bool flag=0;
    int now=0,l=0;
    string password,input;
    password.clear();
    f.open(password_path);
    //文件打开失败
    if (!f) {
        cout << "文件打开出错！" << endl;
        getchar();
        return 0;
    }
    //从文件中读出密码
    while (!f.eof()) {
        f.read(&password[now], 1);
        if ((password[now]>='A' && password[now]<='Z') || (password[now]>='0' && password[now]<='9') || (password[now]>='a' && password[now]<='z')) {
            now++;
            continue;
        }
        else
            break;
    }
    f.close();
    //密码解密
    for (int i=0; i<now; i++) {
        password[i]-=i+1;
    }
    //三次尝试机会
    for (int i=1; i<=3; i++) {
        l=0;
        fflush(stdin);
        system("clear");
        input.clear();
        flag=0;
        cout << "请输入管理员密码" << endl;
        //用*号代替输入的密码
        while ((input[l]=getchar())!=EOF && input[l]!='\n') {
            l++;
            printf("\b*");
        }
        //如果长度都不对，直接错误
        if (l!=now) {
            if (i==3) {
                cout << "对不起，登陆机会用尽，正在退出管理员模式。" << endl;
                getchar();
                return 0;
            }
            cout << "密码错误！您还有" << 3-i << "次尝试机会。" << endl;
            continue;
        }
        //长度正确后逐位进行比较
        for (int j=0; j<now; j++) {
            if (password[j]==input[j]) {
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
        //如果有某一位不相同
        if (flag) {
            cout << "密码错误！您还有" << 3-i << "次尝试机会。" << endl;
            getchar();
            continue;
        }
        //密码匹配
        else
        {
            cout << "登陆成功！" << endl;
            getchar();
            return 1;
        }
    }
    return 0;
}

//管理员模式菜单打印
void administrator_menu_print()
{
    system("clear");
    cout << "现在是管理员模式，您可以进行以下操作。" << endl;
    cout << "1.增加一个城市" << endl;
    cout << "2.为已有的城市增加交通路径信息" << endl;
    cout << "3.删除某个城市" << endl;
    cout << "4.删除某条已有的路径信息" << endl;
    cout << "5.修改某条已有的路径信息" << endl;
    cout << "0.退出管理员模式" << endl;
}

//清除输入缓存
void input_clear()
{
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
}

//查找城市是否存在
bool city_lookfor(string name)
{
    ifstream f;
    bool flag=0;
    string t=city_path;
    t+=name;
    f.open(t.c_str());
    if (!f)
        flag=0;
    else
        flag=1;
    f.close();
    return flag;
}

//交通路径的输出
void edge_print(Edge x)
{
    cout << "起点:" << x.start_place << " ";
    cout << "终点:" << x.end_place << " ";
    cout << "出发时间:" << x.start_time.hour << ":" << x.start_time.min << " ";
    cout << "抵达时间:" << x.end_time.hour << ":" << x.end_time.min << " ";
    cout << "花费金额:" << x.cost_money << " ";
    cout << "交通方式:" << x.vehicle << endl;
}

//验证路径是否相等
bool edge_same(Edge a,Edge b)
{
    if (a.start_place!=b.start_place || a.end_place!=b.end_place)
        return 0;
    if (time_same(a.start_time, b.start_time)==0) {
        return 0;
    }
    if (time_same(a.end_time, b.end_time)==0) {
        return 0;
    }
    if (a.cost_money!=b.cost_money) {
        return 0;
    }
    if (a.vehicle!=b.vehicle) {
        return 0;
    }
    return 1;
}

//判断时间大小
bool time_compare(Time a,Time b)
{
    long long int sa=0,sb=0;
    sa=(a.hour*60)+a.min;
    sb=(b.hour*60)+b.min;
    return sa>=sb;
}

bool time_compare1(Time a,Time b)
{
    long long int sa=0,sb=0;
    sa=(a.hour*60)+a.min;
    sb=(b.hour*60)+b.min;
    return sa>sb;
}

//判断时间相等
bool time_same(Time a,Time b)
{
    long long int sa,sb;
    sa=a.hour*60+a.min;
    sb=b.hour*60+b.min;
    return sa==sb;
}

//Edge的赋值
void edge_assign(Edge *a,Edge *b)
{
    a->start_place=b->start_place;
    a->end_place=b->end_place;
    a->start_time=b->start_time;
    a->end_time=b->end_time;
    a->cost_money=b->cost_money;
    a->cost_time=b->cost_time;
    a->vehicle=b->vehicle;
}

//乘客模式菜单打印
void passenger_menu_print()
{
    system("clear");
    cout << "您现在处于乘客模式，可以进行以下操作" << endl;
    cout << "1.查询城市的出发信息" << endl;
    cout << "2.查询城市的抵达信息" << endl;
    cout << "3.查询交通工具的信息" << endl;
    cout << "4.查询所有交通信息" << endl;
    cout << "5.路线规划服务" << endl;
    cout << "0.退出乘客模式" << endl;
}

//城市的出发查询
void city_demand_out()
{
    vector<Edge>V;
    string city_name,filename;
    Edge temp;
    ifstream f;
    system("clear");
    cout << "请输入您要查询的城市" << endl;
    cin >> city_name;
    filename=city_path_out;
    filename+=city_name;
    f.open(filename.c_str());
    if (!f) {
        cout << "不存在该城市！" << endl;
        return;
    }
    V.clear();
    temp.start_place=city_name;
    while (f >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        V.push_back(temp);
    }
    f.close();
    int choose;
    cout << "请选择您想要的浏览排序方式" << endl;
    cout << "1.出发时间升序" << endl;
    cout << "2.出发时间降序" << endl;
    cout << "3.抵达时间升序" << endl;
    cout << "4.抵达时间降序" << endl;
    cout << "5.花费金额升序" << endl;
    cout << "6.花费金额降序" << endl;
    cout << "7.花费时间升序" << endl;
    cout << "8.花费时间降序" << endl;
    cout << "9.乱序" << endl;
    cin >> choose;
    switch (choose) {
        case 1:
            sort(V.begin(), V.end(), sort_cmp1);
            break;
        case 2:
            sort(V.begin(), V.end(), sort_cmp2);
            break;
        case 3:
            sort(V.begin(), V.end(), sort_cmp3);
            break;
        case 4:
            sort(V.begin(), V.end(), sort_cmp4);
            break;
        case 5:
            sort(V.begin(), V.end(), sort_cmp5);
            break;
        case 6:
            sort(V.begin(), V.end(), sort_cmp6);
            break;
        case 7:
            sort(V.begin(), V.end(), sort_cmp7);
            break;
        case 8:
            sort(V.begin(), V.end(), sort_cmp8);
            break;
        case 9:
            break;
        default:
            cout << "输入有误，默认乱序输出" << endl;
            break;
    }
    for (long long int i=0; i<V.size(); i++) {
        edge_print(V[i]);
    }
    V.clear();
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
    getchar();
}

//城市的抵达查询
void city_demand_in()
{
    vector<Edge>V;
    string city_name,filename;
    Edge temp;
    ifstream f;
    system("clear");
    cout << "请输入您要查询的城市" << endl;
    cin >> city_name;
    filename=city_path_in;
    filename+=city_name;
    f.open(filename.c_str());
    if (!f) {
        cout << "不存在该城市！" << endl;
        return;
    }
    V.clear();
    temp.end_place=city_name;
    while (f >> temp.start_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >> temp.vehicle) {
        V.push_back(temp);
    }
    f.close();
    int choose;
    cout << "请选择您想要的浏览排序方式" << endl;
    cout << "1.出发时间升序" << endl;
    cout << "2.出发时间降序" << endl;
    cout << "3.抵达时间升序" << endl;
    cout << "4.抵达时间降序" << endl;
    cout << "5.花费金额升序" << endl;
    cout << "6.花费金额降序" << endl;
    cout << "7.花费时间升序" << endl;
    cout << "8.花费时间降序" << endl;
    cout << "9.乱序" << endl;
    cin >> choose;
    switch (choose) {
        case 1:
            sort(V.begin(), V.end(), sort_cmp1);
            break;
        case 2:
            sort(V.begin(), V.end(), sort_cmp2);
            break;
        case 3:
            sort(V.begin(), V.end(), sort_cmp3);
            break;
        case 4:
            sort(V.begin(), V.end(), sort_cmp4);
            break;
        case 5:
            sort(V.begin(), V.end(), sort_cmp5);
            break;
        case 6:
            sort(V.begin(), V.end(), sort_cmp6);
            break;
        case 7:
            sort(V.begin(), V.end(), sort_cmp7);
            break;
        case 8:
            sort(V.begin(), V.end(), sort_cmp8);
            break;
        case 9:
            break;
        default:
            cout << "输入有误，默认乱序输出" << endl;
            break;
    }
    for (long long int i=0; i<V.size(); i++) {
        edge_print(V[i]);
    }
    V.clear();
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
    getchar();
}

//交通工具信息查询
void vehicle_demand()
{
    vector<Edge>V;
    string vehicle_name,filename;
    Edge temp;
    ifstream f;
    system("clear");
    cout << "请输入您要查询的交通工具" << endl;
    cin >> vehicle_name;
    filename=vehicle_path;
    filename+=vehicle_name;
    f.open(filename.c_str());
    if (!f) {
        cout << "不存在该交通工具！" << endl;
        return;
    }
    V.clear();
    temp.vehicle=vehicle_name;
    while (!f.eof() && f >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time) {
        V.push_back(temp);
    }
    f.close();
    int choose;
    cout << "请选择您想要的浏览排序方式" << endl;
    cout << "1.出发时间升序" << endl;
    cout << "2.出发时间降序" << endl;
    cout << "3.抵达时间升序" << endl;
    cout << "4.抵达时间降序" << endl;
    cout << "5.花费金额升序" << endl;
    cout << "6.花费金额降序" << endl;
    cout << "7.花费时间升序" << endl;
    cout << "8.花费时间降序" << endl;
    cout << "9.乱序" << endl;
    cin >> choose;
    switch (choose) {
        case 1:
            sort(V.begin(), V.end(), sort_cmp1);
            break;
        case 2:
            sort(V.begin(), V.end(), sort_cmp2);
            break;
        case 3:
            sort(V.begin(), V.end(), sort_cmp3);
            break;
        case 4:
            sort(V.begin(), V.end(), sort_cmp4);
            break;
        case 5:
            sort(V.begin(), V.end(), sort_cmp5);
            break;
        case 6:
            sort(V.begin(), V.end(), sort_cmp6);
            break;
        case 7:
            sort(V.begin(), V.end(), sort_cmp7);
            break;
        case 8:
            sort(V.begin(), V.end(), sort_cmp8);
            break;
        case 9:
            break;
        default:
            cout << "输入有误，默认乱序输出" << endl;
            break;
    }
    for (long long int i=0; i<V.size(); i++) {
        edge_print(V[i]);
    }
    V.clear();
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
    getchar();
}

//交通总信息查询
void total_demand()
{
    vector<Edge>V;
    Edge temp;
    ifstream f;
    system("clear");
    f.open(total_path);
    while (V.size()) {
        V.pop_back();
    }
    while (f >> temp.start_place >> temp.end_place >> temp.start_time.hour >> temp.start_time.min >> temp.end_time.hour >> temp.end_time.min >> temp.cost_money >> temp.cost_time >>temp.vehicle) {
        V.push_back(temp);
    }
    f.close();
    int choose;
    cout << "请选择您想要的浏览排序方式" << endl;
    cout << "1.出发时间升序" << endl;
    cout << "2.出发时间降序" << endl;
    cout << "3.抵达时间升序" << endl;
    cout << "4.抵达时间降序" << endl;
    cout << "5.花费金额升序" << endl;
    cout << "6.花费金额降序" << endl;
    cout << "7.花费时间升序" << endl;
    cout << "8.花费时间降序" << endl;
    cout << "9.乱序" << endl;
    cin >> choose;
    cout << V.size() << endl;
    switch (choose) {
        case 1:
            sort(V.begin(), V.end(), sort_cmp1);
            break;
        case 2:
            sort(V.begin(), V.end(), sort_cmp2);
            break;
        case 3:
            sort(V.begin(), V.end(), sort_cmp3);
            break;
        case 4:
            sort(V.begin(), V.end(), sort_cmp4);
            break;
        case 5:
            sort(V.begin(), V.end(), sort_cmp5);
            break;
        case 6:
            sort(V.begin(), V.end(), sort_cmp6);
            break;
        case 7:
            sort(V.begin(), V.end(), sort_cmp7);
            break;
        case 8:
            sort(V.begin(), V.end(), sort_cmp8);
            break;
        case 9:
            break;
        default:
            cout << "输入有误，默认乱序输出" << endl;
            break;
    }
    for (long long int i=0; i<V.size(); i++) {
        edge_print(V[i]);
    }
    V.clear();
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
    getchar();
}

//路线规划服务
void guide()
{
    system("clear");
    string start,end;
    Time start_time;
    int choose;
    cout << "请输入您的出发地点" << endl;
    cin >> start ;
    cout << "请输入您的目标地点" << endl;
    cin >> end;
    cout << "请输入您的出发时间" << endl;
    scanf("%d:%d",&start_time.hour,&start_time.min);
    cout << "请选择您需要的决策方式" << endl;
    cout << "1.花费时间最少" << endl;
    cout << "2.中转次数最少" << endl;
    cout << "3.花费金额最少" << endl;
    cin >> choose;
    switch (choose) {
        case 1:
            least_time_cost(start,end,start_time);
            break;
        case 2:
            least_transit(start, end, start_time);
            break;
        case 3:
            least_money_cost(start, end, start_time);
            break;
        default:
            break;
    }
}

//最少时间花费决策方式
void least_time_cost(string start,string end,Time start_time)
{
    long long int now=0;
    map<string,Time>M;
    map<string,bool>vis;
    map<string,long long int>num;
    map<string,long long int>D;
    map<string,Edge>fa;
    vector<Edge>E[700];
    Edge temp1;
    Time Set;
    Set.hour=23;
    Set.min=59;
    D.clear();
    M.clear();
    num.clear();
    vis.clear();
    fa.clear();
    string temp,filename;
    ifstream f,f1;
    //将所有城市的初始时间置为Set,距离置为INF
    f.open(city_imf_path);
    while (f >> temp) {
        now++;
        M[temp]=Set;
        D[temp]=INF;
        vis[temp]=0;
        num[temp]=now;
        E[now].clear();
        //打开temp的out文件，找出邻接城市
        filename=city_path_out;
        filename+=temp;
        f1.open(filename.c_str());
        temp1.start_place=temp;
        while (!f1.eof() && f1 >> temp1.end_place >> temp1.start_time.hour >> temp1.start_time.min >> temp1.end_time.hour >> temp1.end_time.min >> temp1.cost_money >> temp1.cost_time >> temp1.vehicle) {
            E[now].push_back(temp1);
        }
        f1.close();
    }
    f.close();
    //SPFA求最短路
    D[start]=time_change(start_time);
    M[start]=start_time;
    queue<string>Q;
    //清空队列
    while (!Q.empty()) {
        Q.pop();
    }
    Q.push(start);
    while (!Q.empty()) {
        temp=Q.front();
        Q.pop();
        vis[temp]=0;
        //进行松弛
        for (int i=0; i<E[num[temp]].size(); i++) {
            if (time_compare(M[temp], E[num[temp]][i].start_time)==0 && D[E[num[temp]][i].end_place]>time_change(E[num[temp]][i].end_time)) {
                if (time_compare(E[num[temp]][i].end_time, M[E[num[temp]][i].end_place])==0) {
                    M[E[num[temp]][i].end_place]=E[num[temp]][i].end_time;
                    fa[E[num[temp]][i].end_place]=E[num[temp]][i];
                }
                D[E[num[temp]][i].end_place]=time_change(E[num[temp]][i].end_time);
                if (!vis[E[num[temp]][i].end_place]) {
                    vis[E[num[temp]][i].end_place]=1;
                    Q.push(E[num[temp]][i].end_place);
                }
            }
        }
    }
    if (!fa.count(end)) {
        cout << "无法到达指定城市！" << endl;
    }
    else
    {
        long long int money=0;
        cout << "找到路径如下：" << endl;
        vector<Edge>Pt;
        Pt.clear();
        string now=end;
        Edge temp;
        temp.start_place=end;
        while (now!=start) {
            temp=fa[now];
            now=temp.start_place;
            Pt.push_back(temp);
            money+=temp.cost_money;
        }
        for (long int i=Pt.size()-1; i>=0; i--) {
            edge_print(Pt[i]);
        }
        cout << "最终抵达时间为" << M[end].hour << ":" << M[end].min << endl;
        cout << "最终花费金额为" << money << "元" << endl;
        Pt.clear();
    }
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
    getchar();
}

//最少中转次数决策方式
void least_transit(string start,string end,Time start_time)
{
    int now=0;
    string temp,filename;
    ifstream f,f1;
    map<string,Edge>fa;
    map<string,Time>Ti;
    map<string,int>num;
    map<string,bool>vis;
    vector<Edge>E[700];
    queue<string>Q;
    Time Set;
    Set.hour=23;
    Set.min=59;
    Edge temp1;
    fa.clear();
    Ti.clear();
    num.clear();
    vis.clear();
    //将队列清空
    while (!Q.empty()) {
        Q.pop();
    }
    //从文件中将邻接表读出来
    f.open(city_imf_path);
    while (f >> temp) {
        now++;
        num[temp]=now;
        Ti[temp]=Set;
        vis[temp]=0;
        filename=city_path_out;
        filename+=temp;
        f1.open(filename.c_str());
        temp1.start_place=temp;
        while (!f1.eof() && f1 >> temp1.end_place >> temp1.start_time.hour >> temp1.start_time.min >> temp1.end_time.hour >> temp1.end_time.min >> temp1.cost_money >> temp1.cost_time >> temp1.vehicle) {
            E[now].push_back(temp1);
        }
        f1.close();
    }
    //BFS求最少中转
    Ti[start]=start_time;
    vis[start]=1;
    Q.push(start);
    while (!Q.empty()) {
        temp=Q.front();
        Q.pop();
        if (temp==end) {
            break;
        }
        for (int i=0; i<E[num[temp]].size(); i++) {
            if (vis[E[num[temp]][i].end_place]==0 && time_compare1(Ti[temp], E[num[temp]][i].start_time)==0) {
                if (time_compare(Ti[E[num[temp]][i].end_place], E[num[temp]][i].end_time)==1) {
                    Ti[E[num[temp]][i].end_place]=E[num[temp]][i].end_time;
                    fa[E[num[temp]][i].end_place]=E[num[temp]][i];
                }
                vis[E[num[temp]][i].end_place]=1;
                Q.push(E[num[temp]][i].end_place);
                if (fa.count(E[num[temp]][i].end_place)==0) {
                    fa[E[num[temp]][i].end_place]=E[num[temp]][i];
                }
            }
        }
    }
    if (fa.count(end)==0) {
        cout << "无法到达指定城市！" << endl;
    }
    else
    {
        long long int money=0;
        int sum=0;
        cout << "找到路径如下:" << endl;
        vector<Edge>Pt;
        Pt.clear();
        string now=end;
        Edge temp;
        temp.start_place=end;
        while (now!=start) {
            temp=fa[now];
            now=temp.start_place;
            Pt.push_back(temp);
            money+=temp.cost_money;
        }
        for (long int i=Pt.size()-1; i>=0; i--) {
            sum++;
            edge_print(Pt[i]);
        }
        cout << "最终抵达时间为" << Ti[end].hour << ":" << Ti[end].min << endl;
        cout << "最终花费金额为" << money << "元" << endl;
        cout << "总共中转次数为" << sum << "次" << endl;
        Pt.clear();
    }
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
    getchar();
}

//最少金额花费决策方式
void least_money_cost(string start,string end,Time start_time)
{
    long long int now=0;
    map<string,Time>M;
    map<string,bool>vis;
    map<string,long long int>num;
    map<string,long long int>D;
    map<string,Edge>fa;
    vector<Edge>E[700];
    Edge temp1;
    Time Set;
    Set.hour=23;
    Set.min=59;
    D.clear();
    M.clear();
    num.clear();
    vis.clear();
    fa.clear();
    string temp,filename;
    ifstream f,f1;
    //将所有城市的初始时间置为Set,距离置为INF
    f.open(city_imf_path);
    while (f >> temp) {
        now++;
        M[temp]=Set;
        D[temp]=INF;
        vis[temp]=0;
        num[temp]=now;
        E[now].clear();
        //打开temp的out文件，找出邻接城市
        filename=city_path_out;
        filename+=temp;
        f1.open(filename.c_str());
        temp1.start_place=temp;
        while (!f1.eof() && f1 >> temp1.end_place >> temp1.start_time.hour >> temp1.start_time.min >> temp1.end_time.hour >> temp1.end_time.min >> temp1.cost_money >> temp1.cost_time >> temp1.vehicle) {
            E[now].push_back(temp1);
        }
        f1.close();
    }
    f.close();
    //SPFA求最短路
    D[start]=0;
    M[start]=start_time;
    queue<string>Q;
    //清空队列
    while (!Q.empty()) {
        Q.pop();
    }
    Q.push(start);
    while (!Q.empty()) {
        temp=Q.front();
        Q.pop();
        vis[temp]=0;
        //进行松弛
        for (int i=0; i<E[num[temp]].size(); i++) {
            if (time_compare(M[temp], E[num[temp]][i].start_time)==0 && D[E[num[temp]][i].end_place]>D[temp]+E[num[temp]][i].cost_money) {
                if (time_compare(E[num[temp]][i].end_time, M[E[num[temp]][i].end_place])==0) {
                    M[E[num[temp]][i].end_place]=E[num[temp]][i].end_time;
                }
                D[E[num[temp]][i].end_place]=D[temp]+E[num[temp]][i].cost_money;
                fa[E[num[temp]][i].end_place]=E[num[temp]][i];
                if (!vis[E[num[temp]][i].end_place]) {
                    vis[E[num[temp]][i].end_place]=1;
                    Q.push(E[num[temp]][i].end_place);
                }
            }
        }
    }
    if (!fa.count(end)) {
        cout << "无法到达指定城市！" << endl;
    }
    else
    {
        long long int money=0;
        cout << "找到路径如下：" << endl;
        vector<Edge>Pt;
        Pt.clear();
        string now=end;
        Edge temp;
        temp.start_place=end;
        while (now!=start) {
            temp=fa[now];
            now=temp.start_place;
            Pt.push_back(temp);
            money+=temp.cost_money;
        }
        for (long int i=Pt.size()-1; i>=0; i--) {
            edge_print(Pt[i]);
        }
        cout << "最终抵达时间为" << Pt[0].end_time.hour << ":" << Pt[0].end_time.min << endl;
        cout << "最终花费金额为" << money << "元" << endl;
        Pt.clear();
    }
    char c;
    while ((c=getchar())!='\n' && c!=EOF);
    getchar();
    
}

//以下都是sort时使用的cmp函数
int sort_cmp1(Edge a,Edge b)
{
    if (time_compare(a.start_time, b.start_time)) {
        return 0;
    }
    return 1;
}

int sort_cmp2(Edge a,Edge b)
{
    if (time_compare1(a.start_time, b.start_time)) {
        return 1;
    }
    return 0;
}

int sort_cmp3(Edge a,Edge b)
{
    if (time_compare(a.end_time, b.end_time)) {
        return 0;
    }
    return 1;
}

int sort_cmp4(Edge a,Edge b)
{
    if (time_compare1(a.end_time, b.end_time)) {
        return 1;
    }
    return 0;
}

int sort_cmp5(Edge a,Edge b)
{
    return a.cost_money<b.cost_money;
}

int sort_cmp6(Edge a,Edge b)
{
    return a.cost_money>b.cost_money;
}

int sort_cmp7(Edge a,Edge b)
{
    return a.cost_time<b.cost_time;
}

int sort_cmp8(Edge a,Edge b)
{
    return a.cost_time>b.cost_time;
}

long long int time_change(Time a)
{
    long long int out=0;
    out=a.hour*60;
    out+=a.min;
    return out;
}

int main(int argc, const char * argv[]) {
    mode_select();
    return 0;
}
