#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<map>

using namespace std;

const int INF = 0x3f3f3f3f;


const int num_of_points = 27;	//!!修改 1,：点数
const int deadline = 30;	//期限
const int initial_money = 10000; //初始金钱
const int base_income = 1000; //基本收益
const int weight_limit = 1200; //负重上限
const int water_weight = 3, water_price = 5, food_weight = 2, food_price = 10; //价格与重量 

bool* mine_list = new bool[num_of_points + 1], bool* village_list = new bool[num_of_points + 1];
//bool mine_list[num_of_points + 1] = {}, village_list[num_of_points + l] = {};//改成动态分配内存

int water_consumption_list[3] = { 5,8,10 }, food_consumption_list[3] = { 7,6,10 }; //消耗列表
int weather_list[deadline] = { 1,1,0,2,0,1,2,0,1,1,2,1,0,1,1,1,2,2,1,1,0,0,1,0,2,1,0,0,1,1 };
//0晴朗,1高温，2沙暴


struct state
{
	char i, j;
	short k, l;
	state(short ii = 0, short jj = 0, short kk = 0, short ll = 0) :i(ii), j(jj), k(kk), l(ll) {}
	bool operator!=(const state& st2) {
		return i != st2.i || j != st2.j || k != st2.k || l != st2.l;
	}
};
	

vector<short> world_map[num_of_points + 1];
short wmap[num_of_points + 1][num_of_points + 1]
{ {},{2,25},{1,3},{2,25,4},{3,25,24,5},{4,24,6},{5,24,23,7},{6,8,22},{7,9,22},{8,22,21,17,16,15,10},{9,15,11}


};
//地图输入不完整


//!!修改2：地图
map<short,short> mapping;


short* dp[deadline + 1][num_of_points + 1][weight_limit / water_weight + 1];
	//dp[i]	[1]表示第i天结束时，j点有k水、1食物情况下的最多金钱
state* dp_state[deadline + 1][num_of_points + 1][weight_limit / water_weight + l];


//更新规则：采用"我为人人”型dp
/*天数i从0循环到29,编号j从1-10, k,l完全循环
更新停留、挖矿、走动
若(k,l减去行动代价后均为正，则与原有值取较大值)

注意：每天开始时对村庄点状态进行更新
(需要四重循环，对于每个k,l,向上k',l'进行计算更新，计算量600多亿,*30天),
	但特别注意，向上更新时，一旦更新不动就可以break.比如对于某个k,l,
	循环k',l'向上更新，一旦更新不动，直接对k',l'双循环break
共5种更新：起点买，村庄买，停留，挖矿，走动
*/

void inline init_space()
{
	for (int i = 0; i <= deadline; ++i)
		for (int j = 0; j <= num_of_points; ++j)
			for (int k = 0; k <= weight_limit / water_weight; ++k)
			{
				dp[i][j][k] = new short[(weight_limit - k * 3) / 2 + 1]; //加了之后堆不会损坏 
				dp_state[i][j][k] = new state[(weight_limit - k * 3) / 2 + 1];
			}
}

void inline init()
{
	for (int i = 1; i <= num_of_points; ++i)
	{
		mapping[i] = i;
		for (int j = 0; j <= num_of_points && wmap[i][j]; ++j)
			world_map[i].push_back(wmap[i][j]);
	}
	//!修改3：映射,村庄、矿表
	mine_list[12] = 1; village_list[15] = 1;

	for (int i = 0; i <= deadline; ++i)
		for (int j = 0; j <= num_of_points; ++j)
			for (int k = 0; k <= weight_limit / water_weight; ++k)
				for (int l = 0; k * 3 + l * 2 <= weight_limit; ++l) {
					dp[i][j][k][1] = -INF;
				}
	dp[0][1][0][0] = initial_money;
	for (int k = 0; k <= weight_limit / water_weight; ++k) {
		int money_left = dp[0][1][0][0] - k * water_price, weight_left = weight_limit - k * water_weight;
		if (money_left < 0)
			break;
		for (int l = 0; l <= weight_limit / food_weight; ++l) {
			int money_left2 = money_left - l * food_price;
			if (money_left2<0 || l * food_weight>weight_left)
				break;
			if (money_left2 > dp[0][1][k][1])
			{
				dp[0][1][k][1] = money_left2;
				dp_state[0][1][k][1] = state(0, 1, 0, 0);
			}
			//cout«dp[0] [1] [k] [1]«,\n*;
		}
	}
}


inline void buy(int i, int j, int k, int l)
{
	int max_food = weight_limit / food_weight;
	for (int m = k; m <= weight_limit / water_weight; ++m) {
		for (int n = l; m * 3 + n * 2 <= weight_limit && n < max_food; ++n)
		{
			if (m == k && n == l) continue;
			int money_left = dp[i][j][k][1] - (m - k) * water_price * 2 - (n - 1) * food_price * 2;
			if (money_left <= dp[i][j][m][n] || money_left < 0) // I \
			 三角形区域的右上部分三角无需再搜索了，其他还是要更新的
			{
				max_food = n;
				break;
			}
			dp[i][j][m][n] = money_left;
			dp_state[i][j][m][n] = state(i, j, k, l);
		}
	}
}
int main()
{
freopen("l_complete_result. txt", "w",stdout); // ! !修改4：输出文件名
init_space();
init();
int best_ever = -INF;
for (int i = 0; i<deadline; ++i) {
int ii = i + 1;
//cerr<<"i=,,«i« * \n';
for (int j = l; j <= num_of_points; ++j) {
	if (village_list[j]) {
		//每天开始更新下一天前,村庄先购物更新
		for (int k = 0; k <= weight_limit / water_weight; ++k)
			for (int l = 0; k * 3 + l * 2 <= weight_limit; ++l) 
				if (dp[i][j][k][l] >= 0) 
				{
					buy(i, j, k, l); //cout<<"更新村庄！ "<<endl;
				}
	}

//更新停留
int                                                      //原代码food_consumption后面不全
water_consumption = water_consumption_list[weather_list[i]],food_consumption = food_consumption_list[weather_list[i]] 

for (int k = water_consumption.; k <= weight_limit / water_weight; ++k) {
for (int 1 = food_consumption; k * 3 + l * 2 <= weight_limit; ++l) {
 int kk = k - water_consumption,ll = l - food_consumption;
if (dp[i][j][k][1] >= 0 && dp[i][j][k][l] > dp[ii][j][kk][11])
dp[ii][j][kk][ll] = dp[i][j][k][1];
dp_state[ii][j][kk][ll] = state(i, j ,k, 1);
//cout«i«' '«j«" "«k«" "«1«" "«dp[i] [j] [k] [l]«'\n'; }
}
}
〃更新挖矿
if (mine_list[j]) {
water__consumpt ion = water_consumption_list[weather_list[i]] * 3, f ood^ consumpt ion = f ood_consumpt ion_lis - for (int k = water_consumption; k <= weight_limit / water_weight; ++k) {
for (int 1 = food ^ consumption; k * 3 + l * 2 <= weight_limit; ++1) {
 int kk = k - water_consumption,ll = l - food_consumption;
if (dp[i][j][k][1] >= 0 && dp[i][j][k][l] + base_income > dp[ii][j][kk][11]) {
dp[ii][j][kk][11] = dp[i][j][k][1] + base_income; dp_state[ii][j][kk][ll] = state(i, j ,k,l);
}
/*for(int k=0;k<=400;++k)
for (int 1 =0;k*3+l*2<=1200;++1)
if (dp[i] [j] [k] [1] >9900)
cout«i«1 '«j«H "«k<<" H<<1<<" H<<dp[i] [j] [k] [l]«'\n* ;//*/
〃非沙暴，更新走动
if (weather_list[i] < 2) {
water_consumption = water_consumption_list[weather_list[i]] * 2,f ood_ consumpt ion = f ood_consumpt ion_lis - for (vector<short>::iterator
iter = world_map[j].begin(); iter != world_map[j].end(); ++iter) {
for (int k = water_consumption; k <= weight_limit / water_weight; ++k) {
for (int 1 = food__consumption; k * 3 + l * 2 <= weight__limit; ++1) {
int kk = k - water_consumption,ood_consumption;
if (dp[i][j][k][l] >= 0 && dp[i][j][k][l] > dp[ii][*iter][kk][11])
{
dp[ii][*iter][kk][ll] = dp[i][j][k][1];
dp_state[ii][*iter][kk][11] = state(i, j ,k,l);
}
}
}
}
}
}
int t sir get = num_ of _po int s;
int res = -INF;
state last_state;
for (int i = 0; i <= deadline; ++i) {
for (int k = 0; k <= weight_limit / water_weight; ++k) {
for (int 1 = 0; k * 3 + l * 2 <= weight_limit; ++1) {
if (dp[i][target][k][l] > res)
{
res = dp[i][target][k][1];
last_state = state(i,target,k,1);
}
}
}
}
if (res > best_ever) {
cerr << res << " " << best_ever << endl;
best_ever = res;
stack<state> sta;
while (last_state != state(0,0,0,0)) {
sta.push(last_state);
last_state = dp_state[last_state.i][last_state.j][last_state.k][last ^ state.1];
}
cout << i + l << "days,score: " << res << "\nsolution: \n"; 〃此i是外面的大i
while (!sta.empty())
{
last_state = sta.top(); sta.popO;
cout«int(last_state.i) << H "«mapping[last_state . j] «" "«int (last^state.k)<<" "«int (last_state. 1)<<H
"«dp [last^state . i] [last_state. j] [last_state .k] [last_state . 1] «endl;
}
cout << "\n\n\n";
}
}
return 0;
}
