/*
 *  bmp.h
 *  con+
 *
 *  Created by 林 孝樹 on 13/03/02.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 * 
 */
//BitmapHeader
typedef struct _BitmapHeader{
	char    distinct1; //B
	char    distinct2; //M
	int             filesize;//総ファイルサイズ
	short   reserve1;//予約領域(0)
	short   reserve2;//予約領域(0)
	int             offset;//先頭からデータまでのオフセット
}BitmapHeader;

//BitmapInfoHeader
typedef struct _BitmapInfoHeader{
	int             header;//この構造体のサイズ
	int             width;//bitmapの横幅
	int             height;//bitmapの縦幅
	short   plane;//plane数(1)
	short   bits;//bitmapの色数
	int             compression;//圧縮されているかどうか
	int             comp_image_size;//画像全体のサイズ
	int             x_resolution;//解像度
	int             y_resolution;//解像度
	int             pallet_num;//パレット数
	int             important_pallet_num;//パレット数
}BitmapInfoHeader;

///////////////////////////////////////////////////////////////////////////////
//BitmapHeadersの初期化
void InitHeaders(BitmapHeader *header,BitmapInfoHeader *info){
	header->distinct1 = 'B';
	header->distinct2 = 'M';
	header->filesize = 0;
	header->reserve1 = 0;
	header->reserve2 = 0;
	header->offset = 54;
	
	info->header = 40;
	info->width = 0;
	info->height = 0;
	info->plane = 1;
	info->bits = 24;
	info->compression = 0;
	info->comp_image_size = 0;
	info->x_resolution = 0;
	info->y_resolution = 0;
	info->pallet_num = 0;
	info->important_pallet_num = 0;
};
///////////////////////////////////////////////////////////////////////////////
//Bitmapwb_«Ý
void WriteHeader(BitmapHeader *header,FILE *fp){
	fwrite(&(header->distinct1), sizeof(char),1,fp);
	fwrite(&(header->distinct2), sizeof(char),1,fp);
	fwrite(&(header->filesize), sizeof(int),1,fp);
	fwrite(&(header->reserve1), sizeof(short),1,fp);
	fwrite(&(header->reserve2), sizeof(short),1,fp);
	fwrite(&(header->offset), sizeof(int),1,fp);
}
///////////////////////////////////////////////////////////////////////////////
//BitmapInfowb_«Ý
void WriteInfoHeader(BitmapInfoHeader *info,FILE *fp){
	fwrite(&(info->header), sizeof(int),1,fp);
	fwrite(&(info->width), sizeof(int),1,fp);
	fwrite(&(info->height), sizeof(int),1,fp);
	fwrite(&(info->plane), sizeof(short),1,fp);
	fwrite(&(info->bits), sizeof(short),1,fp);
	fwrite(&(info->compression), sizeof(int),1,fp);
	fwrite(&(info->comp_image_size), sizeof(int),1,fp);
	fwrite(&(info->x_resolution), sizeof(int),1,fp);
	fwrite(&(info->y_resolution), sizeof(int),1,fp);
	fwrite(&(info->pallet_num), sizeof(int),1,fp);
	fwrite(&(info->important_pallet_num), sizeof(int),1,fp);
}
///////////////////////////////////////////////////////////////////////////////
//sNZf[^ðBitmapt@CÖ«Þ
int WriteBitmap(const char* filename,int width, int height){
	GLubyte *pixel_data;
	FILE *fp;
	BitmapHeader header;
	BitmapInfoHeader info;
	int alignmentParam;
	//int i=0;
	int j=0;
	int x;
	int y;
	unsigned char zero=0;
	
	///////////////////////////////////////////////////////////////////////////
	// `FbNpÌ
	// f[^i[ÌTCYðÝè
	//glPixelStorei(GL_PACK_ALIGNMENT ,2);
	
	// f[^i[Ì¡ÉûÜéÌoCgÌ{ðæ¾
	glGetIntegerv( GL_PACK_ALIGNMENT,&alignmentParam);
	
	// 1æfRoCgÆ·éÆÐÆÂÌsÍ3*widthoCg{At@
	int glByteWidth;        // ÀÛÌ¡ÌoCg
	
	// f[^ÌÌoCgªalignmentParamÌ{Å é©ð`FbN
	if( width*3%alignmentParam == 0)
		glByteWidth = width*3;
	else
		// »¤ÅÈ¯êÎCalignmentParamÌ{É í¹½ÌoCgTCYÉ·é
		glByteWidth = width*3 + alignmentParam - (width*3)%alignmentParam;
	
	///////////////////////////////////////////////////////////////////////////
	// ÇÝÝ
	// mÛ
	pixel_data = (GLubyte*)malloc((glByteWidth)*(height)*(sizeof(GLubyte)));
	// OpenGLÉæésNZf[^ÌÇÝoµ
	glReadPixels(
				 0,0,
				 width,height,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 pixel_data);
	
	///////////////////////////////////////////////////////////////////////////
	// t@CI[v
	if( ( fp = fopen(filename, "wb") )==NULL){
		return -1;
	}
	//wb_\¢ÌÌú»
	InitHeaders(&header, &info);
	//BitmapTCY
	info.width = width;
	info.height = height*2;
	int writeWidth;
	
	///////////////////////////////////////////////////////////////////////////
	// BITMAPpÌ¡Ì
	// f[^ÌÌoCgª4Ì{Å é©ð`FbN
	if( width*3%4 == 0)
		writeWidth = width*3;
	else
		// »¤ÅÈ¯êÎC4Ì{É í¹½ÌoCgTCYÉ·é
		writeWidth = width*3 + 4 - (width*3)%4;
	
	///////////////////////////////////////////////////////////////////////////
	//t@CeÊ
	header.filesize =
	writeWidth*height*2               //rbgîñÊ
	+ 14                                    //BitmapHeader\¢ÌTCY
	+ 40;                                   //BitmapInfoHeader\¢ÌTCY
	//wb_«Ý
	WriteHeader(&header,fp);
	WriteInfoHeader(&info,fp);
	
	///////////////////////////////////////////////////////////////////////////
	// C[Wf[^«Ý
	for( y=0 ; y < height ; y++ ){
		// f[^ðBGRÌÅ«Ý
		for( x=0 ; x < width ; x++ ){
			j=fwrite((pixel_data+x*3+glByteWidth*y+2),sizeof(GLubyte),1,fp);
			j=fwrite((pixel_data+x*3+glByteWidth*y+1),sizeof(GLubyte),1,fp);
			j=fwrite((pixel_data+x*3+glByteWidth*y),sizeof(GLubyte),1,fp);
		}
		// ÌoCgª4Ì{ÅÈ¢Æ«ÍOÅßé
		if( width*3%4 != 0)
			for( int j=0;j<4-(width*3)%4;j++)
				fwrite(&zero,sizeof(GLubyte),1,fp);
	}
	
	///////////////////////////////////////////////////////////////////////////
	// Jú
	free(pixel_data);
	// t@CN[Y
	fclose(fp);
	return 0;
}


//追記
int add_WriteBitmap(const char* filename,int width, int height){
	GLubyte *pixel_data;
	FILE *fp;
  BitmapHeader header;
	BitmapInfoHeader info;
	int alignmentParam;
	int j=0;
	int x;
	int y;
	unsigned char zero=0;
	
	
	glGetIntegerv( GL_PACK_ALIGNMENT,&alignmentParam);
	
	int glByteWidth;
	
	if( width*3%alignmentParam == 0)
		glByteWidth = width*3;
	else
		glByteWidth = width*3 + alignmentParam - (width*3)%alignmentParam;
	
	
	pixel_data = (GLubyte*)malloc((glByteWidth)*(height)*(sizeof(GLubyte)));
	glReadPixels(0,0,width,height,GL_RGB,GL_UNSIGNED_BYTE,pixel_data);
	
	
	if( ( fp = fopen(filename, "a") )==NULL){
		return -1;
	}

	InitHeaders(&header, &info);

	info.width = width;
	info.height = height;
	int writeWidth;
	
	
	if( width*3%4 == 0)
		writeWidth = width*3;
	else
		writeWidth = width*3 + 4 - (width*3)%4;
	
	
	header.filesize =
  writeWidth*height               //rbgîñÊ
	+ 14                                    //BitmapHeader\¢ÌTCY
	+ 40;                                   //BitmapInfoHeader\¢ÌTCY
	//wb_«Ý
	//WriteHeader(&header,fp);
	//WriteInfoHeader(&info,fp);
	
	
	for( y=0 ; y < height ; y++ ){
		for( x=0 ; x < width ; x++ ){
			j=fwrite((pixel_data+x*3+glByteWidth*y+2),sizeof(GLubyte),1,fp);
			j=fwrite((pixel_data+x*3+glByteWidth*y+1),sizeof(GLubyte),1,fp);
			j=fwrite((pixel_data+x*3+glByteWidth*y),sizeof(GLubyte),1,fp);
		}
		if( width*3%4 != 0)
			for( int j=0;j<4-(width*3)%4;j++)
				fwrite(&zero,sizeof(GLubyte),1,fp);
	}
	
		free(pixel_data);
	fclose(fp);
	return 0;
}

