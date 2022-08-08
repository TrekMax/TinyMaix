/* Copyright 2022 Sipeed Technology Co., Ltd. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "stdio.h"
#include "tinymaix.h"

#define  TM_GET_US()       ((uint32_t)(micros()))

#define TM_DBGT_INIT()     uint32_t _start,_finish;uint32_t _time;_start=TM_GET_US();
#define TM_DBGT_START()    _start=TM_GET_US();
#define TM_DBGT(x)         {_finish=TM_GET_US();\
                            _time = (_finish-_start);\
                            Serial.print("===use ");Serial.print(_time);Serial.print("us\n");\
                            _start=TM_GET_US();}

#include <stdint.h>
#define MDL_BUF_LEN (960)
#define LBUF_LEN (360)
const uint8_t mdl_data[920] PROGMEM={\
  0x4d, 0x41, 0x49, 0x58, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x06, 0x00, 0xc0, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 
  0x01, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x03, 0x00, 0x00, 
  0x03, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x01, 0x00, 0x03, 0x00, 0x0d, 0x00, 0x0d, 0x00, 0x01, 0x00, 
  0x81, 0x80, 0x80, 0x3b, 0x80, 0xff, 0xff, 0xff, 0x68, 0x9d, 0x6b, 0x3c, 0x80, 0xff, 0xff, 0xff, 
  0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 
  0xb8, 0xfc, 0x51, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x50, 0x7f, 0x30, 0xed, 0x10, 0x17, 0x9b, 0xc8, 
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0x3d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x10, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0x00, 0x0d, 0x00, 0x0d, 0x00, 0x01, 0x00, 0x03, 0x00, 0x06, 0x00, 0x06, 0x00, 0x03, 0x00, 
  0x68, 0x9d, 0x6b, 0x3c, 0x80, 0xff, 0xff, 0xff, 0x40, 0x47, 0x57, 0x3c, 0x80, 0xff, 0xff, 0xff, 
  0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 
  0xa6, 0x15, 0xf4, 0x3b, 0x51, 0x1d, 0x45, 0x3b, 0x98, 0x06, 0xcf, 0x3b, 0x00, 0x00, 0x00, 0x00, 
  0xea, 0x00, 0x03, 0x9a, 0x81, 0xd0, 0xfb, 0x09, 0x09, 0x13, 0x47, 0x5a, 0xda, 0x4c, 0x7f, 0xf9, 
  0x44, 0x56, 0x23, 0x16, 0x11, 0x24, 0x10, 0x09, 0x81, 0xc5, 0xd7, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x08, 0x90, 0xff, 0xff, 0xc5, 0xfe, 0x00, 0x00, 0x92, 0xe3, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x28, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x03, 0x00, 0x00, 
  0x03, 0x00, 0x06, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x02, 0x00, 0x02, 0x00, 0x06, 0x00, 
  0x40, 0x47, 0x57, 0x3c, 0x80, 0xff, 0xff, 0xff, 0xfe, 0xcd, 0x65, 0x3d, 0x80, 0xff, 0xff, 0xff, 
  0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 
  0x18, 0xa6, 0x35, 0x3d, 0x64, 0xd6, 0xfd, 0x3c, 0x16, 0x84, 0x37, 0x3d, 0x92, 0x5a, 0x07, 0x3d, 
  0xb7, 0xfa, 0xb2, 0x3c, 0x7e, 0xd4, 0x13, 0x3d, 0xb0, 0x2a, 0xc4, 0x26, 0x2d, 0x00, 0xad, 0x81, 
  0xe9, 0xfc, 0x0d, 0xf3, 0x10, 0x08, 0xec, 0xfa, 0x04, 0x06, 0x0d, 0x2f, 0xde, 0x21, 0x0c, 0xef, 
  0x1e, 0xe7, 0x06, 0x81, 0xcd, 0xc2, 0xef, 0xf8, 0x07, 0x04, 0xd2, 0xe2, 0x0f, 0x39, 0x40, 0xed, 
  0x05, 0x04, 0xfa, 0xd2, 0xd1, 0xad, 0xdb, 0x15, 0x11, 0xdf, 0xf0, 0x0f, 0xf4, 0x0f, 0xf8, 0x14, 
  0xde, 0x0e, 0x08, 0x17, 0x7f, 0x3a, 0x2a, 0x13, 0x0c, 0x02, 0xfd, 0x28, 0x0f, 0x21, 0xec, 0xcd, 
  0xd3, 0x0a, 0x25, 0x33, 0x12, 0xf1, 0x45, 0x18, 0x1a, 0xc4, 0xc1, 0xd9, 0xe8, 0x07, 0x01, 0x81, 
  0x00, 0x0c, 0xde, 0xb6, 0x04, 0xd4, 0x12, 0x25, 0xf0, 0x43, 0x05, 0xd4, 0xd4, 0x09, 0xa7, 0x30, 
  0x36, 0xb1, 0xef, 0x3b, 0x2b, 0xcf, 0x81, 0x14, 0x0d, 0xe9, 0xbc, 0xf9, 0x03, 0x29, 0x5c, 0x57, 
  0xb6, 0xa6, 0xd0, 0xff, 0x22, 0x02, 0xd8, 0x04, 0x16, 0xff, 0x08, 0xf1, 0xb4, 0xb9, 0x0a, 0x00, 
  0x14, 0x3d, 0xcc, 0xcc, 0xde, 0xd3, 0xca, 0xdd, 0x41, 0x35, 0xf1, 0x9a, 0xa3, 0xc3, 0xe2, 0x09, 
  0x27, 0xd1, 0xdd, 0x11, 0xe4, 0x81, 0xd5, 0xd6, 0xb5, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x25, 0xc3, 0xff, 0xff, 0x03, 0x81, 0xff, 0xff, 0x00, 0xb7, 0x00, 0x00, 0x46, 0x73, 0xff, 0xff, 
  0xff, 0x9b, 0xff, 0xff, 0x2d, 0x03, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 
  0xa8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x02, 0x00, 0x06, 0x00, 
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x06, 0x00, 0xfe, 0xcd, 0x65, 0x3d, 0x80, 0xff, 0xff, 0xff, 
  0x11, 0xef, 0xc5, 0x3c, 0x80, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xd0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xb0, 0x03, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x06, 0x00, 
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x0a, 0x00, 0x11, 0xef, 0xc5, 0x3c, 0x80, 0xff, 0xff, 0xff, 
  0x4f, 0x75, 0x1d, 0x3e, 0x3f, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 
  0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0xba, 0x05, 0x3d, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xb9, 0x0f, 0xcc, 0x08, 0x38, 0xf3, 0xc8, 0x1d, 0xd8, 0xa0, 0xd9, 0x44, 0x13, 0x9b, 0x17, 0x04, 
  0x2f, 0xe9, 0xfa, 0xea, 0x27, 0xf6, 0x28, 0x90, 0x28, 0xe6, 0x09, 0xee, 0x81, 0x31, 0xe6, 0xf8, 
  0x1b, 0x19, 0x0c, 0xda, 0xd2, 0xc7, 0xb3, 0x2f, 0xc9, 0x23, 0x21, 0xfd, 0x25, 0xae, 0x19, 0xef, 
  0xf3, 0x3a, 0xcf, 0x08, 0xe0, 0xc5, 0x29, 0x26, 0x0c, 0xd9, 0xb8, 0xdb, 0x00, 0x00, 0x00, 0x00, 
  0x8c, 0xdf, 0xff, 0xff, 0x0d, 0xc7, 0xff, 0xff, 0xb3, 0xf2, 0xff, 0xff, 0x40, 0xe2, 0xff, 0xff, 
  0x84, 0xd4, 0xff, 0xff, 0xac, 0xf3, 0xff, 0xff, 0x86, 0xb5, 0xff, 0xff, 0x19, 0xf6, 0xff, 0xff, 
  0x75, 0xdc, 0xff, 0xff, 0xfa, 0xe3, 0xff, 0xff, 0x03, 0x00, 0x01, 0x00, 0x30, 0x00, 0x00, 0x00, 
  0xb0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x0a, 0x00, 
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x0a, 0x00, 0x4f, 0x75, 0x1d, 0x3e, 0x3f, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x3b, 0x80, 0xff, 0xff, 0xff, 
};


const uint8_t mnist_pic[28*28] PROGMEM={
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,116,125,171,255,255,150, 93,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,169,253,253,253,253,253,253,218, 30,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,169,253,253,253,213,142,176,253,253,122,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0, 52,250,253,210, 32, 12,  0,  6,206,253,140,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0, 77,251,210, 25,  0,  0,  0,122,248,253, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0, 31, 18,  0,  0,  0,  0,209,253,253, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,117,247,253,198, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 76,247,253,231, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,253,253,144,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,176,246,253,159, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,234,253,233, 35,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,198,253,253,141,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0, 78,248,253,189, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0, 19,200,253,253,141,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,134,253,253,173, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,248,253,253, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,248,253,253, 43, 20, 20, 20, 20,  5,  0,  5, 20, 20, 37,150,150,150,147, 10,  0,
  0,  0,  0,  0,  0,  0,  0,  0,248,253,253,253,253,253,253,253,168,143,166,253,253,253,253,253,253,253,123,  0,
  0,  0,  0,  0,  0,  0,  0,  0,174,253,253,253,253,253,253,253,253,253,253,253,249,247,247,169,117,117, 57,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,118,123,123,123,166,253,253,253,155,123,123, 41,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

tm_err_t layer_cb(tm_mdl_t* mdl, tml_head_t* lh)
{   //dump middle result
    return TM_OK;
    int h = lh->out_dims[1];
    int w = lh->out_dims[2];
    int ch= lh->out_dims[3];
    mtype_t* output = TML_GET_OUTPUT(mdl, lh);
    Serial.print("Layer ");Serial.print(mdl->layer_i);Serial.print(" callback ========\n");
    for(int y=0; y<h; y++){
       Serial.print("[");
        for(int x=0; x<w; x++){
            Serial.print("[");
            for(int c=0; c<ch; c++){
                Serial.print(output[(y*w+x)*ch+c]);Serial.print(",");
            }
            Serial.print("],");
        }
        Serial.print("],\n");
    }
    Serial.print("\n");
    return TM_OK;
}

static void parse_output(tm_mat_t* outs)
{
    tm_mat_t out = outs[0];
    float* data  = out.dataf;
    float maxp = 0;
    int maxi = -1;
    for(int i=0; i<10; i++){
        //TM_PRINTF("%d: %.3f\n", i, data[i]);
        Serial.print(i);Serial.print(": ");Serial.print(int(data[i]*100));Serial.print("\n");
        if(data[i] > maxp) {
            maxi = i;
            maxp = data[i];
        }
    }
    Serial.print("### Predict output is: Number ");Serial.print(maxi);Serial.print(", prob=");Serial.print(int(maxp*100));
    Serial.print("\n");
    return;
}


#define IMG_L   (28)
#define IMG_CH  (1)
#define CLASS_N (10)

static uint8_t mdl_buf[MDL_BUF_LEN];

void setup() {
    Serial.begin(115200);
    //printf_begin();
    TM_DBGT_INIT();
    Serial.print("mnist demo\n");
    tm_mdl_t mdl;

    for(int i=0; i<28*28; i++){
        Serial.print(pgm_read_byte(&mnist_pic[i])>>4, HEX);
        if(i%28==27)Serial.print("\n");
    }

    tm_mat_t in_uint8 = {3,IMG_L,IMG_L,IMG_CH, (mtype_t*)mnist_pic};
    tm_mat_t in = {3,IMG_L,IMG_L,IMG_CH, NULL};
    tm_mat_t outs[1];
    tm_err_t res;
    //tm_stat((tm_mdlbin_t*)mdl_data); 

    res = tm_load(&mdl, mdl_data, mdl_buf, layer_cb, &in);
    if(res != TM_OK) {
        TM_PRINTF("tm model load err %d\n", res);
        return -1;
    }

    res = tm_preprocess(&mdl, TMPP_UINT2INT, &in_uint8, &in); 

    TM_DBGT_START();
    res = tm_run(&mdl, &in, outs);
    TM_DBGT("tm_run");
    if(res==TM_OK) parse_output(outs);  
    else TM_PRINTF("tm run error: %d\n", res);
    tm_unload(&mdl);                  
    return ;
}

void loop() {
  // put your main code here, to run repeatedly:

}
