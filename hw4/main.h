#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>


using namespace std;



void ReadBMP(char* file_in,char* file_out,float r){
    
	
	FILE* fin=fopen(file_in,"rb");
    FILE* fout=fopen(file_out,"wb");

    unsigned char header[54];
    fread(header,sizeof(unsigned char),54,fin); 
    fwrite(header,sizeof(unsigned char),54,fout);
    
    short bits=*(short*)&header[28];
    int bytes=bits/8;
    int rgb_offset=*(int*)&header[10];

    int width=*(int*)&header[18];				//width and height is stored in 18, 22
    int height=*(int*)&header[22];
    

    unsigned char* color_plate=new unsigned char[rgb_offset-54];
    
	fread(color_plate,sizeof(unsigned char),rgb_offset-54,fin);
    fwrite(color_plate,sizeof(unsigned char),rgb_offset-54,fout);

    int padded=(width*bytes+bytes)&(~bytes);
    
	unsigned char* data=new unsigned char[padded];
    

    for(int row=0;row<height;row++){
    	
        fread(data,sizeof(unsigned char),padded,fin);
        
        for(int column=0;column<width*bytes;column=column+bytes){
        	
            int R=data[column];
			int G=data[column+1];
			int B=data[column+2];
			
			try{
				if(R*r>255||G*r>255||B*r>255){
					data[column]=R*r>255 ? 255:R*r;
					data[column+1]=G*r>255 ? 255:G*r;
					data[column+2]=B*r>255 ? 255:B*r;
					
					throw "overflow!";
				}
				else{
					data[column]=R*r; 
					data[column+1]=G*r; 
					data[column+2]=B*r;
				}
					
			}
			catch(const char* str){
				cout<<"Pixel("<<column<<","<<row<<") is overflow."<<endl;
			}	
        }
        
        fwrite(data,sizeof(unsigned char),padded,fout);
        
    }
    
    fclose(fin);
    fclose(fout);
    
    
    
    
}

