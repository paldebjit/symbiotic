#include <string.h>
#include <math.h>
#include <assert.h>
// #pragma ACCEL kernel
unsigned char default_function(unsigned int instr, unsigned char* out_mem, unsigned char* DRAM) {
  unsigned int _top;
  unsigned int sram_base;
  for (int x = 0; x < 1; ++x) {
    sram_base = ((instr >> 25) & ((1L << (9 - 25)) - 1));
  }
  unsigned int dram_base;
  for (int x1 = 0; x1 < 1; ++x1) {
    dram_base = ((instr >> 57) & ((1L << (25 - 57)) - 1));
  }
  unsigned int y_size;
  for (int x2 = 0; x2 < 1; ++x2) {
    y_size = ((instr >> 80) & ((1L << (64 - 80)) - 1));
  }
  unsigned int x_size;
  for (int x3 = 0; x3 < 1; ++x3) {
    x_size = ((instr >> 96) & ((1L << (80 - 96)) - 1));
  }
  unsigned int x_stride;
  for (int x4 = 0; x4 < 1; ++x4) {
    x_stride = ((instr >> 112) & ((1L << (96 - 112)) - 1));
  }
  unsigned int store_data;
  for (int y = 0; y < y_size; ++y) {
    for (int x5 = 0; x5 < x_size; ++x5) {
      unsigned int mutate0;
      for (int row = 0; row < 1; ++row) {
        for (int col = 0; col < 16; ++col) {
          DRAM[(((((dram_base + (((unsigned int)y) * x_stride)) + ((unsigned int)x5)) * 16U) + ((unsigned int)(row * 16))) + ((unsigned int)col))] = out_mem[(((unsigned int)(col + (row * 16))) + (((sram_base + (((unsigned int)y) * x_size)) + ((unsigned int)x5)) * 16U))];
        }
      }
    }
  }
}

// #include <string.h>
// #include <math.h>
// #include <assert.h>
// #pragma ACCEL kernel
unsigned char reorder_function(unsigned int instr_1, unsigned char* out_mem_1, unsigned char* DRAM_1) {
  unsigned int _top;
  unsigned int sram_base;
  for (int x = 0; x < 1; ++x) {
    sram_base = ((instr_1 >> 25) & ((1L << (9 - 25)) - 1));
  }
  unsigned int dram_base;
  for (int x1 = 0; x1 < 1; ++x1) {
    dram_base = ((instr_1 >> 57) & ((1L << (25 - 57)) - 1));
  }
  unsigned int y_size;
  for (int x2 = 0; x2 < 1; ++x2) {
    y_size = ((instr_1 >> 80) & ((1L << (64 - 80)) - 1));
  }
  unsigned int x_size;
  for (int x3 = 0; x3 < 1; ++x3) {
    x_size = ((instr_1 >> 96) & ((1L << (80 - 96)) - 1));
  }
  unsigned int x_stride;
  for (int x4 = 0; x4 < 1; ++x4) {
    x_stride = ((instr_1 >> 112) & ((1L << (96 - 112)) - 1));
  }
  unsigned int store_data;
  for (int x5 = 0; x5 < x_size; ++x5) {
    for (int y = 0; y < y_size; ++y) {
      unsigned int mutate0;
      for (int row = 0; row < 1; ++row) {
        for (int col = 0; col < 16; ++col) {
          DRAM_1[(((((dram_base + (((unsigned int)y) * x_stride)) + ((unsigned int)x5)) * 16U) + ((unsigned int)(row * 16))) + ((unsigned int)col))] = out_mem_1[(((unsigned int)(col - (row * 16))) + (((sram_base + (((unsigned int)y) * x_size)) + ((unsigned int)x5)) * 16U))];
        }
      }
    }
  }
}

// Function to declare all arrays, pass values to them and write assertions 
void pass(){

    // Declare arrays for all functions
   unsigned int instr[100];
   unsigned int instr_1[100];
   unsigned char out_mem[100];
   unsigned char out_mem_1[100];
   unsigned char DRAM[100];
   unsigned char DRAM_1[100];
    
    // Initialize arrays for all functions
    for (int q=0;q<100;q++){
	      instr[q] = 123489;
        instr_1[q] =123489;
        out_mem[q] = 'b';
        out_mem_1[q] = 'b';
        DRAM_1[q] = 'a';
        DRAM[q] = 'a';
        }
    
    default_function(instr, &out_mem, &DRAM);
    reorder_function(instr_1, &out_mem_1, &DRAM_1);
   
    
    // Initialize assertion flag
    int flag_1 = 1, flag_2 = 1, flag_3 = 1;
    
    // Set flag when checking arrays passed in default and loop reorder
    for(int k =0;k<100;k++){
      if(instr[k]!=instr_1[k]){
        flag_1=0;
      }
      if(out_mem[k]!=out_mem_1[k]){
        flag_2=0;
      }
      if(DRAM[k]!=DRAM_1[k]){
              int flag_3 = 0;
      }
      }
    
    //Assertion condition
    assert(flag_1==1);
    assert(flag_2==1);
    assert(flag_3==1);
 }

int main(){
    pass();
    return 0;
}
