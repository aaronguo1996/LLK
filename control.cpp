#include <QtGui>

#include "control.h"
#include <ctime>

Control::Control(int w,int l)
	:width(w),length(l)
{//初始化二维数组，周围一圈为空，内部全部为实
	for(int i = 1; i< width-1; i++)
		for(int j = 1;j < length-1;j++)
			pos[i][j] = 1;
	
	for(int i = 0; i < length; i++){
		pos[0][i] = 0;
		pos[width-1][i] = 0;
	}
	for(int i = 0; i < width; i++){
		pos[i][0] = 0;
		pos[i][length-1] = 0;
	}
}

//检验直线连接
//方法：遍历整条直线，总是从小向大遍历
bool Control::check_none_corner(int x1,int y1,int x2,int y2)
{
	if(x1 == x2){
        if(y1>y2)	std::swap(y1,y2);
		for(int i =y1+1;i<y2;i++)
			if(pos[x1][i])
				return false;
    }else if(y1 == y2){
        if(x1>x2)  std::swap(x1,x2);
		for(int i = x1+1;i<x2;i++)
			if(pos[i][y2])
				return false;
    }else
        return false;
    return true;
}
//检查直线连接
//方法：遍历
bool Control::check_zero_corner(int x1,int y1,int x2,int y2)
{
	cornerPoint = 0;
	return check_none_corner(x1,y1,x2,y2);
}
//检查有一个拐点的情况，并储存拐点数和拐点坐标
//方法：找汇合点
bool Control::check_one_corner(int x1,int y1,int x2,int y2)
{
	if(findInteractPoint(x1,y1,x2,y2)){
		cornerPoint = 1;
		points[0] = x2;
		points[1] = y2;
		return true;
	}
	return false;
}

//检查两个拐点的情况，储存拐点数和坐标
//方法，分成一段直线与一个汇合点的寻找
bool Control::check_two_corner(int x1,int y1,int x2,int y2)
{
	for(int i=0;i<width;++i){
        if((!pos[i][y1]) &&
           check_none_corner(i,y1,x1,y1) &&
           findInteractPoint(i,y1,x2,y2)){
				cornerPoint = 2;
				points[0] = i;
				points[1] = y1;
				points[2] = x2;
				points[3] = y2;
				return true;
		}
    }
	for(int i=0;i<length;++i){
       if((!pos[x1][i]) &&
          check_none_corner(x1,i,x1,y1) &&
          findInteractPoint(x1,i,x2,y2)){
				cornerPoint = 2;
				points[0] = x1;
				points[1] = i;
				points[2] = x2;
				points[3] = y2;
				return true;
		}
    }
    return false;
}

//寻找汇合点
//方法：首先找直线交点处是否为空，然后遍历两条直线
bool Control::findInteractPoint(int &x1,int &y1,int &x2,int &y2)
{
    if(!pos[x1][y2]){
        if(check_none_corner(x1,y1,x1,y2) &&
            check_none_corner(x2,y2,x1,y2)){
			x2 = x1;
            return true;
        }
    }
    if(!pos[x2][y1]){
		if(check_none_corner(x1,y1,x2,y1)&&
			check_none_corner(x2,y2,x2,y1)){
			y2 = y1;
			return true;
		}
    }
    return false;
}

//检查是否相同的图片
bool Control::is_double_button(int x1,int y1,int x2,int y2)
{
	if((x1 == x2) && (y1 == y2))  return false;
	else 						  return true;
}

//是否可以连接
bool Control::isLinkable(int x1,int y1,int x2,int y2)
{
	return (is_double_button(x1,y1,x2,y2)) &&
		   (check_zero_corner(x1,y1,x2,y2)||check_one_corner(x1,y1,x2,y2)||check_two_corner(x1,y1,x2,y2));
}
//是否图片相同
bool Control::is_same_picture(QString pic1,QString pic2)
{
	return pic1 == pic2;
}

//产生随机数组，必须是4的倍数，保证每张图出现4次
void Control::setupRandomArray(int *a,int max)
{
	for(int i = 0;i < max; i++){
		a[4*i] = i;
		a[4*i+1] = i;
		a[4*i+2] = i;
		a[4*i+3] = i;
	}
}
//打乱数组
//方法：从数组末端开始，与前面的任意一个数交换，一直到最前面的两个数交换为止
//实现了数组元素的打乱顺序
void Control::randomPictures(int *a,int max)
{
	srand(time(NULL));
	setupRandomArray(a,max);
	int len = max * 4;
	for(int i = len;i > 0;i--){
		int j = rand() % i;
		int temp = a[j];
		a[j] = a[i-1];
		a[i-1] = temp;
	}
}
//重排
//方法：遍历按钮容器，保存所有现存的图片，重新打乱，重新分配
void Control::rearrange(QVector<QVector<GameButton *> >gamebuttons)
{
	QString pics[maxElements*4];
	srand(time(NULL));
	int count = 0;

	for(int i = 0;i < width-2;i++)
		for(int j = 0;j < length-2;j++)
			if(pos[i+1][j+1])
				count++;

	//存储图片
	int pictures[count];
	for(int i = 0;i < count;i++)
		pictures[i] = i;

	//打乱图片
	for(int i = count;i > 0;i--){
		int j = rand() % i;
		int temp = pictures[j];
		pictures[j] = pictures[i-1];
		pictures[i-1] = temp;
	}

	//
	for(int i = 0;i < width-2;i++)
		for(int j = 0;j < length-2;j++)
			if(pos[i+1][j+1]){
				count--;
				pics[count] = gamebuttons[i][j]->get_image();
			}

	
	for(int i = 0;i < width-2;i++)
		for(int j = 0;j< length-2;j++)
			if(pos[i+1][j+1]){
				gamebuttons[i][j]->set_image(pics[pictures[count]]);
				gamebuttons[i][j]->set_name(pics[pictures[count]]);
				count++;
			}
}
//提示
//方法：遍历按钮容器，从某一个开始寻找与其配对的项，用点击形式标出
void Control::hint(QVector<QVector<GameButton *> >gamebuttons,QString pics1[],QString pics2[])
{
	QVector<GameButton *> t_button;
	for(int i=0;i<width-2;i++){
		for(int j =0;j<length-2;j++){
			if(pos[i+1][j+1]){
				t_button.append(gamebuttons[i][j]);
			}
		}
	}
	for(int i=0;i<width-2;i++)
		for(int j=0;j<length-2;j++)
			for(int m=0;m<t_button.size();m++)
				if(pos[i+1][j+1])
					if(is_same_picture(t_button[m]->get_image(),gamebuttons[i][j]->get_image()) &&
					   isLinkable(t_button[m]->get_x(),t_button[m]->get_y(),gamebuttons[i][j]->get_x(),gamebuttons[i][j]->get_y()))
					   for(int k=0;k<maxElements;k++)
							if(t_button[m]->get_image()==pics1[k]){
								t_button[m]->set_image(pics2[k]);
								gamebuttons[i][j]->set_image(pics2[k]);
								return;
							}
	rearrange(gamebuttons);
}
//判断僵局，若是，则重排
bool Control::isDead(QVector<QVector<GameButton *> >gamebuttons)
{
	QVector<GameButton *> t_button;
	for(int i=0;i<width-2;i++){
		for(int j =0;j<length-2;j++){
			if(pos[i+1][j+1]){
				t_button.append(gamebuttons[i][j]);
			}
		}
	}
	for(int i=0;i<width-2;i++)
		for(int j=0;j<length-2;j++)
			for(int m=0;m<t_button.size();m++)
				if(pos[i+1][j+1])
					if(is_same_picture(t_button[m]->get_image(),gamebuttons[i][j]->get_image()) &&
					   isLinkable(t_button[m]->get_x(),t_button[m]->get_y(),gamebuttons[i][j]->get_x(),gamebuttons[i][j]->get_y()))
								return false;
	rearrange(gamebuttons);
	return true;
}
//判断胜利
bool Control::win(int len)
{
	for(int i=0;i<width-2;i++){
		for(int j =0;j<length-2;j++){
			if((pos[i+1][j+1]) || len==0){
				return false;
			}
		}
	}
	return true;
}
//判断失败
bool Control::lose(int len)
{
	for(int i=0;i<width-2;i++){
		for(int j =0;j<length-2;j++){
			if(len==1){
				return true;
			}
		}
	}
	return false;
}
//按照行寻找最近的那个块
int Control::findBlank(int k,int x,int y)
{
	if(x<y){
		for(int i=x;i<y;i++)
			if(pos[k][i])  return i;
		return -1;
	}else if(x>y){
		for(int i=x;i>y;i--)
			if(pos[k][i])  return i;
		return -1;
	}
}
//按照列寻找最近的那个块
int Control::findRowBlank(int k,int x,int y)
{
	if(x<y){
		for(int i=x;i<y;i++)
			if(pos[i][k])  return i;
		return -1;
	}else if(x>y){
		for(int i=x;i>y;i--)
			if(pos[i][k])  return i;
		return -1;
	}
}
//向下移动
//方法：竖着遍历整个容器，寻找空格时从下向上找，移动物块是从上向下移动，其他方向方法类似
void Control::moveDown(QVector<QVector<GameButton *> >gamebuttons,
						int startRow,int endRow,int startColumn,int endColumn)
{
	for(int i=endRow;i>=startRow;i--){
		for(int j=endColumn;j>=startColumn;j--){//length-3 0
			if(!pos[i+1][j+1]){
				int temp_y = findBlank(i+1,j+1,startColumn);
				if(temp_y!=-1){
					gamebuttons[i][j]->set_image(gamebuttons[i][temp_y-1]->get_image());
					gamebuttons[i][j]->set_name(gamebuttons[i][temp_y-1]->get_image());
					for(int m=temp_y;m<j+1;m++)
						if(pos[i+1][m+1]==0){
							pos[i+1][m+1] = pos[i+1][m];
							pos[i+1][m] = 0;
						}
				}
			}
		}
	}
}

void Control::moveUp(QVector<QVector<GameButton *> >gamebuttons,
					int startRow,int endRow,int startColumn,int endColumn)
{
	for(int i=startRow;i<endRow;i++){
		for(int j=startColumn;j<endColumn;j++){//0 length-2
			if(!pos[i+1][j+1]){
				int temp_y = findBlank(i+1,j+1,endColumn+1);
				if(temp_y!=-1){
					gamebuttons[i][j]->set_image(gamebuttons[i][temp_y-1]->get_image());
					gamebuttons[i][j]->set_name(gamebuttons[i][temp_y-1]->get_image());
					for(int m=temp_y;m>j+1;m--)
						if(pos[i+1][m-1]==0){
							pos[i+1][m-1] = pos[i+1][m];
							pos[i+1][m] = 0;
						}
				}
			}
		}
	}
}

void Control::moveLeft(QVector<QVector<GameButton *> >gamebuttons,
						int startRow,int endRow,int startColumn,int endColumn)
{
	for(int j=startRow;j<endRow;j++){
		for(int i=startColumn;i<endColumn;i++){//0 width-2
			if(!pos[i+1][j+1]){
				int temp_x = findRowBlank(j+1,i+1,endColumn+1);
				if(temp_x!=-1){
					gamebuttons[i][j]->set_image(gamebuttons[temp_x-1][j]->get_image());
					gamebuttons[i][j]->set_name(gamebuttons[temp_x-1][j]->get_image());
					for(int m=temp_x;m>=i+1;m--)
						if(pos[m][j+1]==0){
							pos[m][j+1] = pos[m+1][j+1];
							pos[m+1][j+1] = 0;
						}
				}
			}
		}
	}
}

void Control::moveRight(QVector<QVector<GameButton *> >gamebuttons,
						int startRow,int endRow,int startColumn,int endColumn)
{
	for(int j=endRow;j>=startRow;j--){
		for(int i=endColumn;i>=startColumn;i--){//width-3 0
			if(!pos[i+1][j+1]){
				int temp_x = findRowBlank(j+1,i+1,startColumn);
				if(temp_x!=-1){
					gamebuttons[i][j]->set_image(gamebuttons[temp_x-1][j]->get_image());
					gamebuttons[i][j]->set_name(gamebuttons[temp_x-1][j]->get_image());
					for(int m=temp_x;m<i+1;m++)
						if(pos[m+1][j+1]==0){
							pos[m+1][j+1] = pos[m][j+1];
							pos[m][j+1] = 0;
						}
				}
			}
		}
	}
}
//设置不同的关卡的不同移动方向
void Control::setLevel(int nLevel,QVector<QVector<GameButton *> >gamebuttons)
{
	switch(nLevel)
	{
	case 0://不动
		break;
	case 1://向下
		moveDown(gamebuttons,0,width-3,0,length-3);
		break;
	case 2://向上
		moveUp(gamebuttons,0,width-2,0,length-2);
		break;
	case 3://向左
		moveLeft(gamebuttons,0,length-2,0,width-2);
		break;
	case 4://向右
		moveRight(gamebuttons,0,length-3,0,width-3);
		break;
	case 5://上下集中
		moveDown(gamebuttons,0,width/2-1,0,length-3);
		moveUp(gamebuttons,width/2-1,width-2,0,length-2);
		break;
	case 6://左右集中
		moveLeft(gamebuttons,0,length/2-1,0,width-2);
		moveRight(gamebuttons,length/2-1,length-3,0,width-3);
		break;
	case 7://上下分离
		moveUp(gamebuttons,0,width-2,0,length/2-1);
		moveDown(gamebuttons,0,width-3,length/2-1,length-3);
		break;
	case 8://左右分离
		moveLeft(gamebuttons,0,length-2,0,width/2-1);
		moveRight(gamebuttons,0,length-3,width/2-1,width-3);
		break;
	default:
		break;
	}
	for(int i=0;i<width-2;i++){
		for(int j =0;j<length-2;j++){
			if(pos[i+1][j+1])
				gamebuttons[i][j]->show();
			else
				gamebuttons[i][j]->hide();
		}
	}
}

QString Control::messages[] = 
{
"Congratulations! We award you 2 hints.",
"Congratulations! We award you 5 seconds.",
"Congratulations! We award you 1 life.",
"Congratulations! We award you 3 lives.",
"Congratulations! We award you 10 seconds.",
"It's terrible, you lose 1 hint.",
"I'm sorry but you lose 10 seconds.",
"It's a pity that you lose 1 life.",
"It's sad that you lose 3 hints.",
"It's terrible, you lose 5 seconds"
};

QString Control::getRandomMessage(int temp)
{
	return messages[temp];
}