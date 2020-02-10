#include<bits/stdc++.h>
using namespace std;
char me;
int moves[8][2]= {{1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}};
set<pair<int,int> > min_target;
set<pair<int,int> > max_target;

void create_target()
{
max_target.insert({15,11});
max_target.insert({15,12});
max_target.insert({15,13});
max_target.insert({15,14});
max_target.insert({15,15});
max_target.insert({14,11});
max_target.insert({14,12});
max_target.insert({14,13});
max_target.insert({14,14});
max_target.insert({14,15});
max_target.insert({13,12});
max_target.insert({13,13});
max_target.insert({13,14});
max_target.insert({13,15});
max_target.insert({12,13});
max_target.insert({12,14});
max_target.insert({12,15});
max_target.insert({11,14});
max_target.insert({11,15});
min_target.insert({0,0});
min_target.insert({0,1});
min_target.insert({0,2});
min_target.insert({0,3});
min_target.insert({0,4});
min_target.insert({1,0});
min_target.insert({1,1});
min_target.insert({1,2});
min_target.insert({1,3});
min_target.insert({1,4});
min_target.insert({2,0});
min_target.insert({2,1});
min_target.insert({2,2});
min_target.insert({2,3});
min_target.insert({3,0});
min_target.insert({3,1});
min_target.insert({3,2});
min_target.insert({4,0});
min_target.insert({4,1});
}
bool can_be_pushed(char player,pair<int,int> start,pair<int,int> end,int target)
{
	if(player=='B')
	{
		if(min_target.find(start)==min_target.end()&&min_target.find(end)!=min_target.end())
		return false;
		else if(max_target.find(start)!=max_target.end()&&max_target.find(end)==max_target.end())
		return false;
		else if(target&&(end.first-start.first<0||end.second-start.second<0)&&min_target.find(start)!=min_target.end()&&min_target.find(end)!=min_target.end())
		return false;
	}
	else
	{
		if(max_target.find(start)==max_target.end()&&max_target.find(end)!=max_target.end())
		return false;
		if(min_target.find(start)!=min_target.end()&&min_target.find(end)==min_target.end())
		return false;
		else if(target&&(end.first-start.first>0||end.second-start.second>0)&&max_target.find(start)!=max_target.end()&&max_target.find(end)!=max_target.end())
		return false;
	}
	return true;
}

//Euclidean*1000
int black_heur[16][16]={{21213,20518,19849,19209,18601,18027,17492,17000,16552,16155,15811,15524,15297,15132,15033,15000},
{20518,19798,19104,18439,17804,17204,16643,16124,15652,15231,14866,14560,14317,14142,14035,14000},
{19849,19104,18384,17691,17029,16401,15811,15264,14764,14317,13928,13601,13341,13152,13038,13000},
{19209,18439,17691,16970,16278,15620,15000,14422,13892,13416,13000,12649,12369,12165,12041,12000},
{18601,17804,17029,16278,15556,14866,14212,13601,13038,12529,12083,11704,11401,11180,11045,11000},
{18027,17204,16401,15620,14866,14142,13453,12806,12206,11661,11180,10770,10440,10198,10049,10000},
{17492,16643,15811,15000,14212,13453,12727,12041,11401,10816,10295,9848,9486,9219,9055,9000},
{17000,16124,15264,14422,13601,12806,12041,11313,10630,10000,9433,8944,8544,8246,8062,8000},
{16552,15652,14764,13892,13038,12206,11401,10630,9899,9219,8602,8062,7615,7280,7071,7000},
{16155,15231,14317,13416,12529,11661,10816,10000,9219,8485,7810,7211,6708,6324,6082,6000},
{15811,14866,13928,13000,12083,11180,10295,9433,8602,7810,7071,6403,5830,5385,5099,5000},
{15524,14560,13601,12649,11704,10770,9848,8944,8062,7211,6403,5656,5000,4472,4123,4000},
{15297,14317,13341,12369,11401,10440,9486,8544,7615,6708,5830,5000,4242,3605,3162,3000},
{15132,14142,13152,12165,11180,10198,9219,8246,7280,6324,5385,4472,3605,2828,2236,2000},
{15033,14035,13038,12041,11045,10049,9055,8062,7071,6082,5099,4123,3162,2236,1414,1000},
{15000,14000,13000,12000,11000,10000,9000,8000,7000,6000,5000,4000,3000,2000,1000,0}};

int white_heur[16][16]={{0,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000},
{1000,1414,2236,3162,4123,5099,6082,7071,8062,9055,10049,11045,12041,13038,14035,15033},
{2000,2236,2828,3605,4472,5385,6324,7280,8246,9219,10198,11180,12165,13152,14142,15132},
{3000,3162,3605,4242,5000,5830,6708,7615,8544,9486,10440,11401,12369,13341,14317,15297},
{4000,4123,4472,5000,5656,6403,7211,8062,8944,9848,10770,11704,12649,13601,14560,15524},
{5000,5099,5385,5830,6403,7071,7810,8602,9433,10295,11180,12083,13000,13928,14866,15811},
{6000,6082,6324,6708,7211,7810,8485,9219,10000,10816,11661,12529,13416,14317,15231,16155},
{7000,7071,7280,7615,8062,8602,9219,9899,10630,11401,12206,13038,13892,14764,15652,16552},
{8000,8062,8246,8544,8944,9433,10000,10630,11313,12041,12806,13601,14422,15264,16124,17000},
{9000,9055,9219,9486,9848,10295,10816,11401,12041,12727,13453,14212,15000,15811,16643,17492},
{10000,10049,10198,10440,10770,11180,11661,12206,12806,13453,14142,14866,15620,16401,17204,18027},
{11000,11045,11180,11401,11704,12083,12529,13038,13601,14212,14866,15556,16278,17029,17804,18601},
{12000,12041,12165,12369,12649,13000,13416,13892,14422,15000,15620,16278,16970,17691,18439,19209},
{13000,13038,13152,13341,13601,13928,14317,14764,15264,15811,16401,17029,17691,18384,19104,19849},
{14000,14035,14142,14317,14560,14866,15231,15652,16124,16643,17204,17804,18439,19104,19798,20518},
{15000,15033,15132,15297,15524,15811,16155,16552,17000,17492,18027,18601,19209,19849,20518,21213}};
void find_board(vector<pair<int,int> > step,vector<vector<char> > &b,char player)
{
	int n=step.size();
	pair<int,int> start=step[0];
	pair<int,int> end=step[n-1];
	b[start.first][start.second]='.';
	b[end.first][end.second]=player;
	
}
double calculate_distance(pair<int,int> start,int player)
{
	double dist;
	int x=start.first;
	int y=start.second;
	if(player=='B')
	{
		dist=sqrt(x*x+y*y);	
	}
	else
	{
		x=abs(x-15);
		y=abs(y-15);
		dist=sqrt(x*x+y*y);
	}
	
	return dist;
}

struct cmp
{  bool operator() (const pair< double,set<vector<pair<int,int> > > :: iterator > &A,const pair< double,set<vector<pair<int,int> > > :: iterator > &B) 
  {
  	double x=A.first;
  	double y=B.first;
    return x<y;
  }
};
typedef struct pq
{
	priority_queue< pair< double,set<vector<pair<int,int> > > :: iterator>, vector< pair <double,set<vector<pair<int,int> > > :: iterator > >, cmp> p;
}pq;
int total;
void change_list(char player,set<pair<int,int> > &ans_target_max
		,set<pair<int,int> > &ans_non_target_max
		,set<pair<int,int> > &target_max
		,set<pair<int,int> > &ans_target_min
		,set<pair<int,int> > &ans_non_target_min
		,set<pair<int,int> > &target_min,vector<pair<int,int> > v)
{
	if(me==player)
	{
		if(player=='B')
			{
				
				if(target_max.find(v[0])!=target_max.end())
				target_max.erase(v[0]);
				else if(ans_non_target_max.find(v[0])!=ans_non_target_max.end())
				ans_non_target_max.erase(v[0]);
				else if(ans_target_max.find(v[0])!=ans_target_max.end())
				ans_target_max.erase(v[0]);
				
				
				if(max_target.find(v[1])!=max_target.end())
				target_max.insert(v[1]);
				else if(min_target.find(v[1])!=min_target.end())
				ans_target_max.insert(v[1]);
				else
				ans_non_target_max.insert(v[1]);
				
			}
			else
			{
				
				if(target_max.find(v[0])!=target_max.end())
				target_max.erase(v[0]);
				else if(ans_non_target_max.find(v[0])!=ans_non_target_max.end())
				ans_non_target_max.erase(v[0]);
				else if(ans_target_max.find(v[0])!=ans_target_max.end())
				ans_target_max.erase(v[0]);
				
				if(min_target.find(v[1])!=min_target.end())
				target_max.insert(v[1]);
				else if(max_target.find(v[1])!=max_target.end())
				ans_target_max.insert(v[1]);
				else
				ans_non_target_max.insert(v[1]);
			}
	}
	
	else
	{
		if(player=='B')
			{
				if(target_min.find(v[0])!=target_min.end())
				target_min.erase(v[0]);
				else if(ans_non_target_min.find(v[0])!=ans_non_target_min.end())
				ans_non_target_min.erase(v[0]);
				else if(ans_target_min.find(v[0])!=ans_target_min.end())
				ans_target_min.erase(v[0]);
				
				if(max_target.find(v[1])!=max_target.end())
				target_min.insert(v[1]);
				else if(min_target.find(v[1])!=min_target.end())
				ans_target_min.insert(v[1]);
				else
				ans_non_target_min.insert(v[1]);
				
			}
			else
			{
				
				if(target_min.find(v[0])!=target_min.end())
				target_min.erase(v[0]);
				else if(ans_non_target_min.find(v[0])!=ans_non_target_min.end())
				ans_non_target_min.erase(v[0]);
				else if(ans_target_min.find(v[0])!=ans_target_min.end())
				ans_target_min.erase(v[0]);
			
				if(min_target.find(v[1])!=min_target.end())
				target_min.insert(v[1]);
				else if(max_target.find(v[1])!=max_target.end())
				ans_target_min.insert(v[1]);
				else
				ans_non_target_min.insert(v[1]);
				
				
			}
	}
}
map<vector<pair<int,int> >,vector<pair<int,int> > >  ans;  
int global_depth;
void next_move(int level,int target,pq &que,vector<pair<int,int> > &step,set<vector<pair<int,int> > > &store,char player,int i,int j,vector<vector<char> > &copy,vector<vector<char> > &update,int jump,int depth,int prev_x,int prev_y)
{
		total++;
		
		if(i>=0&&j>=0&&i<16&&j<16&&jump==true)
		{
			vector<pair<int,int> > tuple;
			tuple.push_back(step[0]);
			tuple.push_back(step[step.size()-1]);
			if(find(store.begin(),store.end(),tuple)==store.end()&&can_be_pushed(player,step[0],step[step.size()-1],target))
			{
			store.insert(tuple);
			double dist_end=calculate_distance({i,j},player);
			
			que.p.push({dist_end,store.find(tuple)});
			if(level==global_depth&&player==me)
			ans[tuple]=step;
			}
		}
			for(int k=0;k<8;k++)
			{
				int dx = moves[k][0];
				int dy = moves[k][1];
				
			
				if(i+dx<0||j+dy<0||i+dx>=16||j+dy>=16)
				{
				continue;	
				}
				
						if(update[i+dx][j+dy]=='.'&&!jump)
						{
						char store_old=update[i][j];
						char store_new=update[i+dx][j+dy];
						update[i][j]='.';
						update[i+dx][j+dy]=player;
						step.push_back({i+dx,j+dy});
						
						vector<pair<int,int> > tuple;
						tuple.push_back(step[0]);
						tuple.push_back(step[step.size()-1]);
						if(find(store.begin(),store.end(),tuple)==store.end()&&can_be_pushed(player,step[0],step[step.size()-1],target))
						{
							store.insert(tuple);
							double dist_end=calculate_distance({i+dx,j+dy},player);
							que.p.push({dist_end,store.find(tuple)});
							if(level==global_depth&&player==me)
							ans[tuple]=step;
						}
						update[i][j]=store_old;
						update[i+dx][j+dy]=store_new;
						step.pop_back();
						
						}
					else
					{
						if(update[i+dx][j+dy]!='.')
						{
							char s=copy[i][j];
							copy[i][j]=',';
							if(((i+2*dx)>=0)&&((i+2*dx)<16)&&((j+2*dy)>=0)&&((j+2*dy)<16)&&(update[i+2*dx][j+2*dy]=='.')&&(copy[i+2*dx][j+2*dy]!=','))
							{
								char store_prev=update[i][j];
								char store_new=update[i+2*dx][j+2*dy];
								update[i+2*dx][j+2*dy]=player;
								update[i][j]='.';
								step.push_back({i+2*dx,j+2*dy});
								vector<pair<int,int> > tuple;	
								tuple.push_back(step[0]);
								tuple.push_back(step[step.size()-1]);
								if(find(store.begin(),store.end(),tuple)==store.end())
									{
											next_move(level,target,que,step,store,player,i+2*dx,j+2*dy,copy,update,true,depth-1,i,j);
									}
									step.pop_back();
							}
								update[i+2*dx][j+2*dy]=store_new;
								update[i][j]=store_prev;
						}
							copy[i][j]=s;
						}
						
					}
			}
}
set<pair<int,int> > find_all_positions(vector<vector<char> > &config,char player)
{
	set<pair<int,int> > res;
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		{
			if(config[i][j]==player)
			res.insert(make_pair(i,j));
		}
	}
	
	return res;
}
void all_positions_to_target_non(vector<vector<char> > &config,set<pair<int,int> > &target,set<pair<int,int> > &ans_target,set<pair<int,int> > &ans_non_target,char player)
{
		set<pair<int,int> > ans=find_all_positions(config,player);
		
		set<pair<int,int> > :: iterator it3;
		for(it3=ans.begin();it3!=ans.end();it3++)
		{
			if(player=='W')
			{
				if(max_target.find(*it3)!=max_target.end())
				{
					ans_target.insert(*it3);
				}
				else if(min_target.find(*it3)!=min_target.end())
				target.insert(*it3);
				else
				ans_non_target.insert(*it3);
			}
			else
			{
				if(min_target.find(*it3)!=min_target.end())
				{
					ans_target.insert(*it3);
				}
				else if(max_target.find(*it3)!=max_target.end())
				target.insert(*it3);
				else
				ans_non_target.insert(*it3);
			}
		}
}
double calculate_score(vector<vector<char> > &config,char player,bool isMax,int d)
{
	int count=0;
	if(me=='W')
	{
		for(int i=0;i<16;i++)
		{
			for(int j=0;j<16;j++)
			{
				if(config[i][j]=='W')
				count=count-white_heur[i][j];
				else if(config[i][j]=='B')
				count=count+black_heur[i][j];
				
				
			}
		}
		

	}
	else
	{
		for(int i=0;i<16;i++)
		{
			for(int j=0;j<16;j++)
			{
				if(config[i][j]=='B')
				count=count-black_heur[i][j];
				else if(config[i][j]=='W')
				count=count+white_heur[i][j];
			}
		}
		
	}
	
	count=count-global_depth;
	return count;
	
}

bool complete(char player,vector<vector<char> > &config,int& win)
{
	if(player=='B')
	{
		set<pair<int,int> > :: iterator it;
		int count=0,count1=0;
		for(it=max_target.begin();it!=max_target.end();it++)
		{
			pair<int,int> v=*it;
			if(config[v.first][v.second]=='B')
			count1++;
			if(config[v.first][v.second]!='.')
			count++;
		}
		if(me=='W')
		{
			if(count1==19)
			win=1;
		}
		if(me=='B')
		{
			if(count1==19)
			win=1;
		}
		if(count==19&&count1>0)
		return true;
	}
	else
	{
		set<pair<int,int> > :: iterator it;
		int count=0,count1=0;
		for(it=min_target.begin();it!=min_target.end();it++)
		{
			pair<int,int> v=*it;
			if(config[v.first][v.second]=='W')
			count1++;
			if(config[v.first][v.second]!='.')
			count++;
		}
		if(me=='W')
		{
			if(count1==19)
			win=1;
		}
		if(me=='B')
		{
			if(count1==19)
			win=1;
		}
		if(count==19&&count1>0)
		return true;
	}
	
	return false;
}
int pru_1,pru_2;
vector<pair<int,int> > result;
int minmax(int alpha,int beta,int depth,vector<vector<char> > &config, bool isMax,char player,set<pair<int,int> > &ans_target_max
		,set<pair<int,int> > &ans_non_target_max
		,set<pair<int,int> > &target_max
		,set<pair<int,int> > &ans_target_min
		,set<pair<int,int> > &ans_non_target_min
		,set<pair<int,int> > &target_min)
{
	int win=-1;
	
	if(depth==0||complete(player,config,win))
	{
		if(win==1&&player==me)
		return INT_MAX;
		else if(win==1&&player!=me)
		return INT_MIN;
		else
		return calculate_score(config,player,isMax,depth);
	}
	
	if(isMax)
	{
		
		int best=INT_MIN;
		vector<vector<char> > copy=config;
		vector<vector<char> > update=config;
		set<vector<pair<int,int> > > store;
		set<pair<int,int> > :: iterator it;
		pq que;
		
			vector<pair<int,int> > step;
	
			for(it=ans_non_target_max.begin();it!=ans_non_target_max.end();it++)
			{
				step.push_back({(*it).first,(*it).second});	
				
				next_move(depth,0,que,step,store,player,(*it).first,(*it).second,copy,update,false,10,-1,-1);
				step.pop_back();
				
			}
		
			
			for(it=target_max.begin();it!=target_max.end();it++)
			{
				step.push_back({(*it).first,(*it).second});
				next_move(depth,0,que,step,store,player,(*it).first,(*it).second,copy,update,false,10,-1,-1);
				step.pop_back();
			}
		
		
		
			
		list<vector<vector<char> > > ::iterator it1;
		
		while(que.p.empty()==false)
		{
			pair<double,set<vector<pair<int,int> > > :: iterator  > res=que.p.top();
			
			set< vector<pair<int,int> > > :: iterator ite= res.second;
			vector<pair<int,int> > v=*(ite);
			find_board(v,config,player);
			change_list(player,ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min,v);
			int val;
			if(player=='W')
			val=minmax(alpha,beta,depth-1,config,false,'B',ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min);
			else
			val=minmax(alpha,beta,depth-1,config,false,'W',ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min);
			if(best<val&&depth==global_depth)
			{
				best=val;
				
				result=v;
				
				
			}	
			best=max(best,val);
			
			alpha=max(alpha,best);
			reverse(v.begin(),v.end());
			find_board(v,config,player);
			change_list(player,ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min,v);
			que.p.pop();
			
			if(beta<=alpha)
			{
				break;
			}
			
		}
		
		return best;
	}
	else
	{
		int best=INT_MAX;	
		vector<vector<char> > copy=config;
		vector<vector<char> > update=config;
		set<vector<pair<int,int> > > store;
		set<pair<int,int> > :: iterator it;
		pq que;
		vector<pair<int,int> > step;
		
		if(ans_target_min.size()!=0)
		{
			for(it=ans_target_min.begin();it!=ans_target_min.end();it++)
			{
				step.push_back({(*it).first,(*it).second});
				next_move(depth,1,que,step,store,player,(*it).first,(*it).second,copy,update,false,10,-1,-1);
				step.pop_back();
			}
				
		}
			for(it=ans_non_target_min.begin();it!=ans_non_target_min.end();it++)
			{
				step.push_back({(*it).first,(*it).second});
				next_move(depth,0,que,step,store,player,(*it).first,(*it).second,copy,update,false,10,-1,-1);
				step.pop_back();
			}
		
			for(it=target_min.begin();it!=target_min.end();it++)
			{
				step.push_back({(*it).first,(*it).second});
				next_move(depth,0,que,step,store,player,(*it).first,(*it).second,copy,update,false,10,-1,-1);
				step.pop_back();
				
			}
			while(que.p.empty()==false)
			{ 
			pair<double,set<vector<pair<int,int> > > :: iterator  > res=que.p.top();
			
			set< vector<pair<int,int> > > :: iterator ite= res.second;
			vector<pair<int,int> > v=*(ite);
			find_board(v,config,player);
			change_list(player,ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min,v);
			int val;
			
			if(player=='W')
			val=minmax(alpha,beta,depth-1,config,true,'B',ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min);
			else
			val=minmax(alpha,beta,depth-1,config,true,'W',ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min);
			
			best=min(best,val);
			beta=min(beta,best);
			
			reverse(v.begin(),v.end());
			
			find_board(v,config,player);
			change_list(player,ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min,v);
			que.p.pop();
			if(beta<=alpha)
			{
					pru_2++;
					break;
			}
			
			}
		return best;
	}
}

bool isAdjacent(pair<int,int> start,pair<int,int> end)
{
	int x=start.first;
	int y=start.second;
	int a=end.first;
	int b=end.second;
	if(abs(x-a)>=2||abs(y-b)>=2)
	return false;
	else
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	FILE *fp1=freopen("input.txt", "r", stdin);
	string move,player;
	vector<vector<char> > board;
	cin>>move>>player;
	float time;
	cin>>time;
	for(int i=0;i<16;i++)
	{
		vector<char> row;
		for(int j=0;j<16;j++)
		{
			char character;
			cin>>character;
			row.push_back(character);
		}
		board.push_back(row);
	}
	
	me=player[0];
	freopen("output.txt","w",stdout);
	create_target();
	if(move=="SINGLE")
	{
		set<pair<int,int> > ans_target_max;
		set<pair<int,int> > ans_non_target_max;
		set<pair<int,int> > target_max;
		set<pair<int,int> > ans_target_min;
		set<pair<int,int> > ans_non_target_min;
		set<pair<int,int> > target_min;
		all_positions_to_target_non(board,target_max,ans_target_max,ans_non_target_max,player[0]);
		set<pair<int,int> > :: iterator it;
		pq que;
		vector<vector<char> > copy=board;
		vector<vector<char> > update=board;
		set<vector<pair<int,int> > > store;
		
		if(ans_target_max.size()!=0)
		{
			vector<pair<int,int> > step;
			for(it=ans_target_max.begin();it!=ans_target_max.end();it++)
			{
				step.push_back({(*it).first,(*it).second});
				update=board;
				copy=board;
				next_move(global_depth,1,que,step,store,player[0],(*it).first,(*it).second,copy,update,false,10,-1,-1);
				step.pop_back();
			}
		}
		if(que.p.empty()==true)
		{
		
			for(it=ans_non_target_max.begin();it!=ans_non_target_max.end();it++)
			{
				vector<pair<int,int> > step;
				step.push_back({(*it).first,(*it).second});
				update=board;
				copy=board;
				next_move(global_depth,0,que,step,store,player[0],(*it).first,(*it).second,copy,update,false,10,-1,-1);
			}
		
			for(it=target_max.begin();it!=target_max.end();it++)
			{
				vector<pair<int,int> > step;
				step.push_back({(*it).first,(*it).second});
				update=board;
				copy=board;
				next_move(global_depth,0,que,step,store,player[0],(*it).first,(*it).second,copy,update,false,10,-1,-1);
			}	
			
		}
			
			pair<double,set<vector<pair<int,int> > > :: iterator  > res=que.p.top();
			
			set< vector<pair<int,int> > > :: iterator ite= res.second;
			vector<pair<int,int> > v=*(ite);
			
			int s=v.size();
			vector<pair<int,int> > step=ans[v];
			if(step.size()==2)
			{
				
				if(isAdjacent(step[0],step[1]))
				{
					cout<<"E ";
					cout<<step[0].second<<","<<step[0].first<<" "<<step[1].second<<","<<step[1].first<<endl;
				}
				else
				{
					cout<<"J ";
					cout<<step[0].second<<","<<step[0].first<<" "<<step[1].second<<","<<step[1].first<<endl;
				}
			}
			else
			{
				int n=step.size();
				for(int i=0;i<n-1;i++)
				{
					
					cout<<"J ";
					cout<<step[i].second<<","<<step[i].first<<" "<<step[i+1].second<<","<<step[i+1].first<<endl;
				}
			}
			
			que.p.pop();
	}
	else if(move=="GAME")
	{
		vector<vector<char> > best_board;
		vector<pair<int,int> > res;
		set<pair<int,int> > ans_target_max;
		set<pair<int,int> > ans_non_target_max;
		set<pair<int,int> > target_max;
		set<pair<int,int> > ans_target_min;
		set<pair<int,int> > ans_non_target_min;
		set<pair<int,int> > target_min;
		all_positions_to_target_non(board,target_max,ans_target_max,ans_non_target_max,player[0]);
		if(player[0]=='B')
		all_positions_to_target_non(board,target_min,ans_target_min,ans_non_target_min,'W');
		else
		all_positions_to_target_non(board,target_min,ans_target_min,ans_non_target_min,'B');
		if(time>=60)
		global_depth=3;
		else if(time<=30&&time>10)
		global_depth=2;
		else if(time<=10)
		global_depth=1;
		
		if(ans_non_target_max.size()>=6&&time>10)
		{
			global_depth=2;
		}
		
		pq que;
		set<pair<int,int> > :: iterator it1;
		vector<vector<char> > update=board;
		vector<vector<char> > copy=board;
		set<vector<pair<int,int> > > store;
		if(ans_target_max.size()!=0)
		{
			vector<pair<int,int> > step;
			for(it1=ans_target_max.begin();it1!=ans_target_max.end();it1++)
			{
				step.push_back({(*it1).first,(*it1).second});
				update=board;
				copy=board;
				//get_state++;
				next_move(global_depth,1,que,step,store,player[0],(*it1).first,(*it1).second,copy,update,false,10,-1,-1);
				step.pop_back();
			}
			
			if(que.p.empty()==false)
			{
			pair<double,set<vector<pair<int,int> > > :: iterator  > res=que.p.top();
			
			set< vector<pair<int,int> > > :: iterator ite= res.second;
			vector<pair<int,int> > v=*(ite);
			find_board(v,board,player[0]);
			best_board=board;
			result=v;
			int s=v.size();
			reverse(v.begin(),v.end());
			find_board(v,board,player[0]);
			}		
		}
		
		if(que.p.empty()==true){
		
		int alpha=INT_MIN;
		int beta=INT_MAX;
		int score;
		
		if(player[0]=='B')
		score=minmax(alpha,beta,global_depth,board, true,'B',ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min);
		else
		score=minmax(alpha,beta,global_depth,board, true,'W',ans_target_max,ans_non_target_max,target_max,ans_target_min,ans_non_target_min,target_min);
		}
		
		vector<pair<int,int> > step=ans[result];

			if(step.size()==2)
			{
				if(isAdjacent(step[0],step[1]))
				{
					cout<<"E ";
					cout<<step[0].second<<","<<step[0].first<<" "<<step[1].second<<","<<step[1].first<<endl;
				}
				else
				{
					cout<<"J ";
					cout<<step[0].second<<","<<step[0].first<<" "<<step[1].second<<","<<step[1].first<<endl;
				}
			}
			else
			{
				int n=step.size();
				for(int i=0;i<n-1;i++)
				{
					
					cout<<"J ";
					cout<<step[i].second<<","<<step[i].first<<" "<<step[i+1].second<<","<<step[i+1].first<<endl;
				}
			}
			
		
	}
	
}
