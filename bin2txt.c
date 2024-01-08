#include <stdio.h>

int main(int argc, char *argv[]){
  
  FILE *fp;
  int data;
  int i;
  int count;
  
  int SS[2];
  int SSS[3];
  
  int year[2];
  int month[2];
  int day[2];
  int hour[2];
  int min[2];
  
  int rain[4];
  int rain_flag[2];
  
  int CWwind_val[4];
  int CWwind_val_flag[2];
  
  int max_wspeed[2];
  int max_wspeed_flag[2];
  int wind_dir_16[4];
  int wind_dir_36[4];
  int ave_windir_16[4];
  int ave_windir_36[4];
  int ave_windir16_flag[1];
  int ave_windir36_flag[1];
  int ave_wind16_yobi[1];
  int ave_wind36_yobi[1];
  
  int ave_wspeed[2];
  int ave_wspeed_flag[2];
  
  unsigned int temp[2];
  unsigned int temp_max[2];
  signed int temp_s[2];
  signed int temp_max_s[2];
  int temp_flag[2];
  int temp_max_flag[2];
  
  int daylight_hours[2];
  int daylight_flag[2];
  
  int snow[2];
  int snow_flag[2];
  
  // マイナスフラグ
  int negative;
  int negative_temp_max;
  
  fp = fopen(argv[1], "rb");
  if(fp == NULL){
    printf("ファイルが開けません。\n");
    return 0;
  }
  
  count=0;
  negative=0;
  negative_temp_max=0;
  
  for(i=0;i<=246240;i++){
    
    data = getc(fp);
    
    // 観測所番号(上2桁)   
    if(count>=2 && count<4){
      if(count==2)
      SS[1] = data;
      if(count==3)
      SS[0] = data;
    }
    
    // 観測所番号(下3桁)    
    if(count>=4 && count<8){
      if(count==4)
      SSS[2] = data;
      if(count==5)
      SSS[1] = data;
      if(count==6)
      SSS[0] = data;
    }
    
    // 年    
    if(count>=40 && count<42){
      if(count==40)
        year[1] = data;
      if(count==41)
        year[0] = data;
    }
    
    // 月
    if(count>=42 && count<44){
      if(count==42)
        month[1] = data;
      if(count==43)
        month[0] = data;
    }
    
    // 日
    if(count>=44 && count<46){
      if(count==44)
        day[1] = data;
      if(count==45)
        day[0] = data;
    }
    
    // 時
    if(count>=46 && count<48){
      if(count==46)
        hour[1] = data;
      if(count==47)
        hour[0] = data;
    }
    
    // 分
    if(count>=48 && count<50){
      if(count==48)
        min[1] = data;
      if(count==49)
        min[0] = data;
    }
    
    // 1分間降水量
    if(count>=55 && count<60){
      if(count==55)
        rain[3] = data;
      if(count==56)
        rain[2] = data;
      if(count==57)
        rain[1] = data;
      if(count==58)
        rain[0] = data;
    } 
    
    // 降水量利用フラグ
    if(count>=59 && count<61){
      if(count==59)
      rain_flag[0] = data;
    } 
    
    // CW風向の最大値
    if(count>=74 && count<78){
      if(count==74)
        CWwind_val[3] = data;
      if(count==75)
        CWwind_val[2] = data;
      if(count==76)
        CWwind_val[1] = data;
      if(count==77)
        CWwind_val[0] = data;
    }
    
    // CW風向の最大値利用フラグ
    if(count>=78 && count<80){
      if(count==78)
        CWwind_val_flag[0] = data;
    }
    
    // 最大瞬間風速
    if(count>=86 && count<87){
      if(count==86)
        max_wspeed[0] = data;
    }
    
    // 最大瞬間風速利用フラグ
    if(count>=90 && count<92){
      if(count==90)
        max_wspeed_flag[0] = data;
    }
    
    // 最大瞬間風速の方向(16)
    if(count>=92 && count<96){
      if(count==92)
        wind_dir_16[3] = data;
      if(count==93)
        wind_dir_16[2] = data;
      if(count==94)
        wind_dir_16[1] = data;
      if(count==95)
        wind_dir_16[0] = data;
    }
    
    // 最大瞬間風速の方向(36)
    if(count>=96 && count<100){
      if(count==96)
        wind_dir_36[3] = data;
      if(count==97)
        wind_dir_36[2] = data;
      if(count==98)
        wind_dir_36[1] = data;
      if(count==99)
        wind_dir_36[0] = data;
    }
    
    // 平均風向(16)
    if(count>=106 && count<110){
      if(count==106)
        ave_windir_16[3] = data;
      if(count==107)
        ave_windir_16[2] = data;
      if(count==108)
        ave_windir_16[1] = data;
      if(count==109)
        ave_windir_16[0] = data;
    }
    
    // 平均風向(16)利用フラグ
    if(count>=110 && count<111){
      if(count==110)
      ave_windir16_flag[0] = data;
    }
    
    // 平均風向(16)予備
    if(count>=111 && count<112){
      if(count==111)
      ave_wind16_yobi[0] = data;
    }
    
    // 平均風向(36)
    if(count>=112 && count<116){
      if(count==112)
      ave_windir_36[3] = data;
      if(count==113)
      ave_windir_36[2] = data;
      if(count==114)
      ave_windir_36[1] = data;
      if(count==115)
      ave_windir_36[0] = data;
    }
    
    // 平均風向(36)利用フラグ
    if(count>=116 && count<118){
      if(count==116)
      ave_windir36_flag[0] = data;
    }
    
    // 平均風向(36)予備
    if(count>=118 && count<120){
      if(count==118)
      ave_wind36_yobi[0] = data;
    }
    
    // 平均風速(10分)
    if(count>=128 && count<132){
      if(count==128)
      ave_wspeed[1] = data;
      if(count==129)
      ave_wspeed[0] = data;
    }
    
    // 平均風速(10分) 利用フラグ
    if(count>=132 && count<134){
      if(count==132)
      ave_wspeed_flag[0] = data;
    }
    
    // 気温 
    if(count>=135 && count<141){
      if(count==135){
          temp[0] = data;
          temp_s[0] = data;
          negative = 0;
      }
        if(count==136){
            temp[1] = data;
              if(data==0xF){
                temp_s[1] = data;
                negative = 1;
      }}
    }
    
    // 気温利用フラグ
    if(count>=139 && count<141){
      if(count==132)
      temp_flag[0] = data;
    }
    
    // 最高気温(前1分間)
    if(count>=141 && count<146){
      if(count==141){
          temp_max[0] = data;
          temp_max_s[0] = data;
          negative_temp_max = 0;
        }
        if(count==142){
            temp_max[1] = data;
              if(data==0xF){
                temp_max_s[1] = data;
                negative_temp_max = 1;
        }}  
    }
    
    // 最高気温(前1分間) 利用フラグ
    if(count>=146 && count<148){
      if(count==146)
        temp_max_flag[0] = data;
    }
    
    // 日照時間
    if(count>=158 && count<160){
      if(count==158)
        daylight_hours[0] = data;
    }
    
    // 日照時間利用フラグ
    if(count>=162 && count<164){
      if(count==162)
      daylight_flag[0] = data;
    }
    
    // 積雪の深さ
    if(count>=165&& count<169){
      if(count==165)
      snow[1] = data;
      if(count==166)
      snow[0] = data;
    }
    
    // 積雪の深さ利用フラグ
    if(count>=169 && count<170){
      if(count==169)
        snow_flag[0] = data;
    }
    
    count++;
    
    if(count%171==0){
      
      printf("%X", SS[0]);
      printf("%X", SS[1]);
      printf(" ");
      printf("%X", SSS[0]);
      printf("%X", SSS[1]);
      printf("%X", SSS[2]);
      printf(" ");
      printf("%X", year[0]);
      printf("%X", year[1]);
      printf(" ");
      printf("%X", month[0]);
      printf("%X", month[1]);
      printf(" ");  
      printf("%X", day[0]);
      printf("%X", day[1]);
      printf(" ");  
      printf("%X", hour[0]);
      printf("%X", hour[1]);
      printf(" ");  
      printf("%X", min[0]);
      printf("%X", min[1]);
      printf(" "); 
      printf("%X", rain[3]);
      printf(" "); 
      printf("%X", ave_windir_16[0]);
      printf("%X", ave_windir_16[1]);
      printf("%X", ave_windir_16[2]);
      printf("%X", ave_windir_16[3]);
      printf(" ");  
      printf("%X", ave_wspeed[0]);
      printf("%X", ave_wspeed[1]);
      printf(" "); 
      printf("%X", ave_wspeed_flag[0]);
      printf("%X", ave_wspeed_flag[1]);
      printf(" "); 
      
      // 01:負を示すフラグ 00:正を示すフラグ 
      if(temp[1]==0xFF) {
        printf("FFF %X", 0xFF-temp_s[0]+1); 
      }else{
        printf("FFE %X", temp[0]);
      }
      
      printf(" "); 
      printf("%X", temp_flag[0]);
      printf(" "); 
      
      printf("%X", daylight_hours[0]);     
      printf(" "); 
      printf("%X", daylight_flag[0]);
      printf(" "); 
      printf("%X", snow[0]);
      printf("%X", snow[1]);
      printf(" "); 
      printf("%X", snow_flag[0]);
      printf("\n"); 
      
      count=0;
      negative = 0;  
      negative_temp_max = 0;
    }
  }

  
  fclose(fp);
  
  return 0;
}
