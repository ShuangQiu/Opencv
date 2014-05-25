//中值滤波和均值滤波
#include<cv.h>
#include<highgui.h>
//#include<stdio.h>

int main(){
	IplImage * image,*image2,*image3;
	image = cvLoadImage("~/tmp.png",0);//以灰度图像的形式读入图片
//    printf("shaokc\n");
	cvNamedWindow("image",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("image2",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("image3",CV_WINDOW_AUTOSIZE);
	//cvSaveImage("E:\\image\\moon.jpg",image,0);
	cvShowImage("image",image);
	//cvWaitKey(0);
	unsigned char * ptr,*dst;
	int i,j,m,n,sum,temp,r,s;
	image2 = cvCreateImage(cvGetSize(image),image->depth,1);
	image3 = cvCreateImage(cvGetSize(image),image->depth,1);
	//模板1 均值
	int tem[9] = {1,1,1,1,1,1,1,1,1};
	//也可以使用改进的高斯模板，但是效果相近
	int tem2[9] = {0};//获取中值时用于排序

	//均值滤波3*3模板的均值
	for( i = 0 ; i < image->height;i++){
		for( j = 0; j< image->width;j++){

			//边界处理
			if(i == 0 || i == image->height || j == 0 || j == image->width){
				ptr = (unsigned char *)image->imageData + i*image->widthStep + j;
				dst = (unsigned char *)image2->imageData+ i*image2->widthStep+ j;
			 	*dst = *ptr; //边界值赋予源图像的值
			}
			else {
				sum = 0;
				for( m = -1 ; m <= 1; m++  ){
					for( n = -1 ; n <= 1 ; n++){
						ptr = (unsigned char *)image->imageData + (i + m)*image->widthStep + j + n;

						sum += (*ptr) * tem[3*(m+1) + n+1];
					}
				}
				dst = (unsigned char *)image2->imageData+ i *image2->widthStep+ j;
				*dst = (unsigned char)((sum +4)/9);//赋新值，四舍五入
			}

		}
	}
//中值滤波 在去除噪声的同时，图像的模糊程度比较小，比均值滤波更加适合
//冲击噪声或者称为椒盐噪声
	for( i = 0 ; i < image->height;i++){
		for( j = 0; j< image->width;j++){

			//边界处理
			if(i == 0 || i == image->height || j == 0 || j == image->width){
				ptr = (unsigned char *)image->imageData + i*image->widthStep + j;
				dst = (unsigned char *)image3->imageData+ i*image3->widthStep+ j;
				*dst = *ptr; //边界值赋予源图像的值
			}
			else {
				temp = 0;
				//将3*3模板覆盖的值拷贝进数组，一边查找中值
				for( m = -1 ; m <= 1; m++  ){
					for( n = -1 ; n <= 1 ; n++){
						ptr = (unsigned char *)image->imageData + (i + m)*image->widthStep + j + n;
						tem2[3*(m+1) +n +1] = *ptr;
						//printf("%d",*ptr);

					}
				}
				//对数组进行冒泡排序
				for(r = 0 ; r <8; r ++){
					for(s = 0 ; s< r -1; s++ ){
						if(tem2[s] > tem2[s+1]){
							temp = tem2[s];
							tem2[s] = tem2[s+1];
							tem2[s+1] = temp;
						}
					}
				}
				//printf("%d",tem2[4]);
				//对新图赋予新值
				dst = (unsigned char *)image3->imageData+ i *image3->widthStep+ j;
				*dst = (unsigned char)(tem2[4]);//赋新值
			}

		}
	}

	cvShowImage("image2",image2);
	cvShowImage("image3",image3);
	cvWaitKey(0);
	cvSaveImage("E:\\image\\Dart2.bmp",image2,0);
	cvSaveImage("E:\\image\\Dart3.bmp",image3,0);
	return 0;
}

