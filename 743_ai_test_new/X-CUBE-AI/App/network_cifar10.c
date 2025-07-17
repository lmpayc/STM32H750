/**
  ******************************************************************************
  * @file    network_cifar10.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-07-16T23:42:54+0800
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network_cifar10.h"
#include "network_cifar10_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_cifar10
 
#undef AI_NETWORK_CIFAR10_MODEL_SIGNATURE
#define AI_NETWORK_CIFAR10_MODEL_SIGNATURE     "0x46a2185906b5d50df566713c2ecfb5af"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2025-07-16T23:42:54+0800"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_CIFAR10_N_BATCHES
#define AI_NETWORK_CIFAR10_N_BATCHES         (1)

static ai_ptr g_network_cifar10_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_cifar10_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_1_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 14400, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19200, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19200, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19200, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19200, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 9600, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 57600, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 57600, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2400, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2400, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2400, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  add_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  add_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1920, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1920, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 480, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 480, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  add_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 480, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_16_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 480, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  add_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 480, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_18_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_19_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 480, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  add_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 480, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_20_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_21_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2880, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 640, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_22_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_23_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 640, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  add_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 640, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_24_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_25_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 640, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  add_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 640, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_26_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_27_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_28_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_29_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  add_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_30_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_31_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  add_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_32_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_16_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_33_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 672, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_34_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  global_average_pooling2d_pool_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  dense_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2304, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1296, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1296, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1296, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_10_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1296, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_10_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4608, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_11_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1728, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_11_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_12_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1728, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_13_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1728, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_13_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_14_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3024, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_14_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_15_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3024, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_15_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_16_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3024, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_16_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 37632, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 143360, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 27, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  add_1_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 10, 8), AI_STRIDE_INIT(4, 4, 4, 64, 640),
  1, &add_1_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  add_2_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 10, 8), AI_STRIDE_INIT(4, 4, 4, 64, 640),
  1, &add_2_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  add_3_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 5, 4), AI_STRIDE_INIT(4, 4, 4, 96, 480),
  1, &add_3_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  add_4_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 5, 4), AI_STRIDE_INIT(4, 4, 4, 96, 480),
  1, &add_4_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  add_5_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 5, 4), AI_STRIDE_INIT(4, 4, 4, 96, 480),
  1, &add_5_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  add_6_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 5, 4), AI_STRIDE_INIT(4, 4, 4, 128, 640),
  1, &add_6_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  add_7_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 5, 4), AI_STRIDE_INIT(4, 4, 4, 128, 640),
  1, &add_7_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  add_8_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 3, 2), AI_STRIDE_INIT(4, 4, 4, 224, 672),
  1, &add_8_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  add_9_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 3, 2), AI_STRIDE_INIT(4, 4, 4, 224, 672),
  1, &add_9_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  add_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 20, 15), AI_STRIDE_INIT(4, 4, 4, 32, 640),
  1, &add_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_10_bias_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &conv2d_10_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 6144, 6144),
  1, &conv2d_10_weights_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_11_bias_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 10, 8), AI_STRIDE_INIT(4, 4, 4, 64, 640),
  1, &conv2d_11_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 4, 384, 6144, 6144),
  1, &conv2d_11_weights_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_12_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &conv2d_12_output_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 6144, 6144),
  1, &conv2d_12_weights_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_13_bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 5, 4), AI_STRIDE_INIT(4, 4, 4, 96, 480),
  1, &conv2d_13_output_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 4, 384, 9216, 9216),
  1, &conv2d_13_weights_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_14_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &conv2d_14_output_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 4, 96, 13824, 13824),
  1, &conv2d_14_weights_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_15_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 5, 4), AI_STRIDE_INIT(4, 4, 4, 96, 480),
  1, &conv2d_15_output_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 4, 576, 13824, 13824),
  1, &conv2d_15_weights_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_16_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &conv2d_16_output_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 4, 96, 13824, 13824),
  1, &conv2d_16_weights_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_17_bias_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 5, 4), AI_STRIDE_INIT(4, 4, 4, 96, 480),
  1, &conv2d_17_output_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 4, 576, 13824, 13824),
  1, &conv2d_17_weights_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_18_bias_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &conv2d_18_output_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 4, 96, 13824, 13824),
  1, &conv2d_18_weights_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_19_bias_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 5, 4), AI_STRIDE_INIT(4, 4, 4, 96, 480),
  1, &conv2d_19_output_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 4, 576, 13824, 13824),
  1, &conv2d_19_weights_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 40, 30), AI_STRIDE_INIT(4, 4, 4, 32, 1280),
  1, &conv2d_1_output_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 8), AI_STRIDE_INIT(4, 4, 64, 512, 512),
  1, &conv2d_1_weights_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_20_bias_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &conv2d_20_output_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 4, 96, 13824, 13824),
  1, &conv2d_20_weights_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_21_bias_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 5, 4), AI_STRIDE_INIT(4, 4, 4, 128, 640),
  1, &conv2d_21_output_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  61, 0x0,
  AI_SHAPE_INIT(4, 144, 1, 1, 32), AI_STRIDE_INIT(4, 4, 576, 18432, 18432),
  1, &conv2d_21_weights_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_22_bias_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &conv2d_22_output_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 4, 128, 24576, 24576),
  1, &conv2d_22_weights_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_23_bias_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 5, 4), AI_STRIDE_INIT(4, 4, 4, 128, 640),
  1, &conv2d_23_output_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  69, 0x0,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 4, 768, 24576, 24576),
  1, &conv2d_23_weights_array, NULL)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_24_bias_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  71, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &conv2d_24_output_array, NULL)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  73, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 4, 128, 24576, 24576),
  1, &conv2d_24_weights_array, NULL)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  74, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_25_bias_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  75, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 5, 4), AI_STRIDE_INIT(4, 4, 4, 128, 640),
  1, &conv2d_25_output_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  76, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  77, 0x0,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 4, 768, 24576, 24576),
  1, &conv2d_25_weights_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_26_bias_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  79, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &conv2d_26_output_array, NULL)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch0, AI_STATIC,
  80, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_26_scratch0_array, NULL)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 4, 128, 24576, 24576),
  1, &conv2d_26_weights_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_27_bias_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  83, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 3, 2), AI_STRIDE_INIT(4, 4, 4, 224, 672),
  1, &conv2d_27_output_array, NULL)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  84, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 192, 1, 1, 56), AI_STRIDE_INIT(4, 4, 768, 43008, 43008),
  1, &conv2d_27_weights_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_28_bias_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  87, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &conv2d_28_output_array, NULL)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  89, 0x0,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 4, 224, 75264, 75264),
  1, &conv2d_28_weights_array, NULL)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_29_bias_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  91, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 3, 2), AI_STRIDE_INIT(4, 4, 4, 224, 672),
  1, &conv2d_29_output_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  93, 0x0,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 4, 1344, 75264, 75264),
  1, &conv2d_29_weights_array, NULL)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_2_bias_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 40, 30), AI_STRIDE_INIT(4, 4, 4, 192, 7680),
  1, &conv2d_2_output_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 1536, 1536),
  1, &conv2d_2_weights_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_30_bias_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  99, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &conv2d_30_output_array, NULL)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  101, 0x0,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 4, 224, 75264, 75264),
  1, &conv2d_30_weights_array, NULL)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_bias, AI_STATIC,
  102, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_31_bias_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  103, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 3, 2), AI_STRIDE_INIT(4, 4, 4, 224, 672),
  1, &conv2d_31_output_array, NULL)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_scratch0, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_31_scratch0_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  105, 0x0,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 4, 1344, 75264, 75264),
  1, &conv2d_31_weights_array, NULL)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_bias, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_32_bias_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_output, AI_STATIC,
  107, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &conv2d_32_output_array, NULL)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_scratch0, AI_STATIC,
  108, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_32_scratch0_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_weights, AI_STATIC,
  109, 0x0,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 4, 224, 75264, 75264),
  1, &conv2d_32_weights_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &conv2d_33_bias_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  111, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 3, 2), AI_STRIDE_INIT(4, 4, 4, 448, 1344),
  1, &conv2d_33_output_array, NULL)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  112, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  113, 0x0,
  AI_SHAPE_INIT(4, 336, 1, 1, 112), AI_STRIDE_INIT(4, 4, 1344, 150528, 150528),
  1, &conv2d_33_weights_array, NULL)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  114, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &conv2d_34_bias_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  115, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 3, 2), AI_STRIDE_INIT(4, 4, 4, 5120, 15360),
  1, &conv2d_34_output_array, NULL)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  117, 0x0,
  AI_SHAPE_INIT(4, 112, 1, 1, 1280), AI_STRIDE_INIT(4, 4, 448, 573440, 573440),
  1, &conv2d_34_weights_array, NULL)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_3_bias_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  119, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 20, 15), AI_STRIDE_INIT(4, 4, 4, 32, 640),
  1, &conv2d_3_output_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  120, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  121, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 4, 192, 1536, 1536),
  1, &conv2d_3_weights_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_4_bias_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  123, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 15), AI_STRIDE_INIT(4, 4, 4, 192, 3840),
  1, &conv2d_4_output_array, NULL)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  124, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  125, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 1536, 1536),
  1, &conv2d_4_weights_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_5_bias_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  127, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 20, 15), AI_STRIDE_INIT(4, 4, 4, 32, 640),
  1, &conv2d_5_output_array, NULL)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  129, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 4, 192, 1536, 1536),
  1, &conv2d_5_weights_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_6_bias_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  131, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 15), AI_STRIDE_INIT(4, 4, 4, 192, 3840),
  1, &conv2d_6_output_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  132, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  133, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 1536, 1536),
  1, &conv2d_6_weights_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_7_bias_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  135, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 10, 8), AI_STRIDE_INIT(4, 4, 4, 64, 640),
  1, &conv2d_7_output_array, NULL)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  137, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 4, 192, 3072, 3072),
  1, &conv2d_7_weights_array, NULL)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_8_bias_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  139, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &conv2d_8_output_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  141, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 6144, 6144),
  1, &conv2d_8_weights_array, NULL)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_9_bias_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  143, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 10, 8), AI_STRIDE_INIT(4, 4, 4, 64, 640),
  1, &conv2d_9_output_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  144, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  145, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 4, 384, 6144, 6144),
  1, &conv2d_9_weights_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_bias, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_bias_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_output, AI_STATIC,
  147, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 40, 30), AI_STRIDE_INIT(4, 4, 4, 64, 2560),
  1, &conv2d_output_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_scratch0, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 3), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv2d_scratch0_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_weights, AI_STATIC,
  149, 0x0,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 4, 12, 192, 576),
  1, &conv2d_weights_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_bias, AI_STATIC,
  150, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_dense_bias_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_output, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_dense_output_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_weights, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 1280, 3, 1, 1), AI_STRIDE_INIT(4, 4, 5120, 15360, 15360),
  1, &dense_dense_weights_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  dense_output, AI_STATIC,
  153, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_output_array, NULL)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_10_bias, AI_STATIC,
  154, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &depthwise_conv2d_10_bias_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_10_output, AI_STATIC,
  155, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &depthwise_conv2d_10_output_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_10_weights, AI_STATIC,
  156, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 144), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &depthwise_conv2d_10_weights_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_11_bias, AI_STATIC,
  157, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &depthwise_conv2d_11_bias_array, NULL)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_11_output, AI_STATIC,
  158, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &depthwise_conv2d_11_output_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_11_weights, AI_STATIC,
  159, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 192), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &depthwise_conv2d_11_weights_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_12_bias, AI_STATIC,
  160, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &depthwise_conv2d_12_bias_array, NULL)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_12_output, AI_STATIC,
  161, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &depthwise_conv2d_12_output_array, NULL)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_12_weights, AI_STATIC,
  162, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 192), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &depthwise_conv2d_12_weights_array, NULL)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_13_bias, AI_STATIC,
  163, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &depthwise_conv2d_13_bias_array, NULL)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_13_output, AI_STATIC,
  164, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 3, 2), AI_STRIDE_INIT(4, 4, 4, 768, 2304),
  1, &depthwise_conv2d_13_output_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_13_weights, AI_STATIC,
  165, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 192), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &depthwise_conv2d_13_weights_array, NULL)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_14_bias, AI_STATIC,
  166, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &depthwise_conv2d_14_bias_array, NULL)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_14_output, AI_STATIC,
  167, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &depthwise_conv2d_14_output_array, NULL)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_14_weights, AI_STATIC,
  168, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 336), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &depthwise_conv2d_14_weights_array, NULL)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_15_bias, AI_STATIC,
  169, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &depthwise_conv2d_15_bias_array, NULL)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_15_output, AI_STATIC,
  170, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &depthwise_conv2d_15_output_array, NULL)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_15_weights, AI_STATIC,
  171, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 336), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &depthwise_conv2d_15_weights_array, NULL)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_16_bias, AI_STATIC,
  172, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &depthwise_conv2d_16_bias_array, NULL)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_16_output, AI_STATIC,
  173, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &depthwise_conv2d_16_output_array, NULL)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_16_weights, AI_STATIC,
  174, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 336), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &depthwise_conv2d_16_weights_array, NULL)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_1_bias, AI_STATIC,
  175, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &depthwise_conv2d_1_bias_array, NULL)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_1_output, AI_STATIC,
  176, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 15), AI_STRIDE_INIT(4, 4, 4, 192, 3840),
  1, &depthwise_conv2d_1_output_array, NULL)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_1_weights, AI_STATIC,
  177, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &depthwise_conv2d_1_weights_array, NULL)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_2_bias, AI_STATIC,
  178, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &depthwise_conv2d_2_bias_array, NULL)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_2_output, AI_STATIC,
  179, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 15), AI_STRIDE_INIT(4, 4, 4, 192, 3840),
  1, &depthwise_conv2d_2_output_array, NULL)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_2_weights, AI_STATIC,
  180, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &depthwise_conv2d_2_weights_array, NULL)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_3_bias, AI_STATIC,
  181, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &depthwise_conv2d_3_bias_array, NULL)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_3_output, AI_STATIC,
  182, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 10, 8), AI_STRIDE_INIT(4, 4, 4, 192, 1920),
  1, &depthwise_conv2d_3_output_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_3_weights, AI_STATIC,
  183, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &depthwise_conv2d_3_weights_array, NULL)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_4_bias, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_4_bias_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_4_output, AI_STATIC,
  185, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &depthwise_conv2d_4_output_array, NULL)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_4_weights, AI_STATIC,
  186, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &depthwise_conv2d_4_weights_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_5_bias, AI_STATIC,
  187, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_5_bias_array, NULL)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_5_output, AI_STATIC,
  188, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &depthwise_conv2d_5_output_array, NULL)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_5_weights, AI_STATIC,
  189, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &depthwise_conv2d_5_weights_array, NULL)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_6_bias, AI_STATIC,
  190, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_6_bias_array, NULL)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_6_output, AI_STATIC,
  191, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 5, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1920),
  1, &depthwise_conv2d_6_output_array, NULL)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_6_weights, AI_STATIC,
  192, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &depthwise_conv2d_6_weights_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_7_bias, AI_STATIC,
  193, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &depthwise_conv2d_7_bias_array, NULL)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_7_output, AI_STATIC,
  194, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &depthwise_conv2d_7_output_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_7_weights, AI_STATIC,
  195, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 144), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &depthwise_conv2d_7_weights_array, NULL)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_8_bias, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &depthwise_conv2d_8_bias_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_8_output, AI_STATIC,
  197, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &depthwise_conv2d_8_output_array, NULL)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_8_weights, AI_STATIC,
  198, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 144), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &depthwise_conv2d_8_weights_array, NULL)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_9_bias, AI_STATIC,
  199, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &depthwise_conv2d_9_bias_array, NULL)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_9_output, AI_STATIC,
  200, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &depthwise_conv2d_9_output_array, NULL)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_9_weights, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 144), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &depthwise_conv2d_9_weights_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_bias, AI_STATIC,
  202, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &depthwise_conv2d_bias_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_output, AI_STATIC,
  203, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 40, 30), AI_STRIDE_INIT(4, 4, 4, 64, 2560),
  1, &depthwise_conv2d_output_array, NULL)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_weights, AI_STATIC,
  204, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 16), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &depthwise_conv2d_weights_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  global_average_pooling2d_pool_output, AI_STATIC,
  205, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &global_average_pooling2d_pool_output_array, NULL)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  input_1_output, AI_STATIC,
  206, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 80, 60), AI_STRIDE_INIT(4, 4, 4, 12, 960),
  1, &input_1_output_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_10_output, AI_STATIC,
  207, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &re_lu_10_output_array, NULL)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_11_output, AI_STATIC,
  208, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &re_lu_11_output_array, NULL)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_12_output, AI_STATIC,
  209, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &re_lu_12_output_array, NULL)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_13_output, AI_STATIC,
  210, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 5, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1920),
  1, &re_lu_13_output_array, NULL)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_14_output, AI_STATIC,
  211, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &re_lu_14_output_array, NULL)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_15_output, AI_STATIC,
  212, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &re_lu_15_output_array, NULL)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_16_output, AI_STATIC,
  213, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &re_lu_16_output_array, NULL)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_17_output, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &re_lu_17_output_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_18_output, AI_STATIC,
  215, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &re_lu_18_output_array, NULL)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_19_output, AI_STATIC,
  216, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &re_lu_19_output_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_1_output, AI_STATIC,
  217, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 40, 30), AI_STRIDE_INIT(4, 4, 4, 64, 2560),
  1, &re_lu_1_output_array, NULL)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_20_output, AI_STATIC,
  218, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &re_lu_20_output_array, NULL)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_21_output, AI_STATIC,
  219, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 5, 4), AI_STRIDE_INIT(4, 4, 4, 576, 2880),
  1, &re_lu_21_output_array, NULL)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_22_output, AI_STATIC,
  220, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &re_lu_22_output_array, NULL)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_23_output, AI_STATIC,
  221, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &re_lu_23_output_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_24_output, AI_STATIC,
  222, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &re_lu_24_output_array, NULL)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_25_output, AI_STATIC,
  223, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &re_lu_25_output_array, NULL)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_26_output, AI_STATIC,
  224, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 5, 4), AI_STRIDE_INIT(4, 4, 4, 768, 3840),
  1, &re_lu_26_output_array, NULL)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_27_output, AI_STATIC,
  225, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 3, 2), AI_STRIDE_INIT(4, 4, 4, 768, 2304),
  1, &re_lu_27_output_array, NULL)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_28_output, AI_STATIC,
  226, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &re_lu_28_output_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_29_output, AI_STATIC,
  227, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &re_lu_29_output_array, NULL)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_2_output, AI_STATIC,
  228, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 40, 30), AI_STRIDE_INIT(4, 4, 4, 192, 7680),
  1, &re_lu_2_output_array, NULL)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_30_output, AI_STATIC,
  229, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &re_lu_30_output_array, NULL)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_31_output, AI_STATIC,
  230, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &re_lu_31_output_array, NULL)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_32_output, AI_STATIC,
  231, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &re_lu_32_output_array, NULL)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_33_output, AI_STATIC,
  232, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 3, 2), AI_STRIDE_INIT(4, 4, 4, 1344, 4032),
  1, &re_lu_33_output_array, NULL)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_34_output, AI_STATIC,
  233, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 3, 2), AI_STRIDE_INIT(4, 4, 4, 5120, 15360),
  1, &re_lu_34_output_array, NULL)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_3_output, AI_STATIC,
  234, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 15), AI_STRIDE_INIT(4, 4, 4, 192, 3840),
  1, &re_lu_3_output_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_4_output, AI_STATIC,
  235, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 15), AI_STRIDE_INIT(4, 4, 4, 192, 3840),
  1, &re_lu_4_output_array, NULL)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_5_output, AI_STATIC,
  236, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 15), AI_STRIDE_INIT(4, 4, 4, 192, 3840),
  1, &re_lu_5_output_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_6_output, AI_STATIC,
  237, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 15), AI_STRIDE_INIT(4, 4, 4, 192, 3840),
  1, &re_lu_6_output_array, NULL)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_7_output, AI_STATIC,
  238, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 10, 8), AI_STRIDE_INIT(4, 4, 4, 192, 1920),
  1, &re_lu_7_output_array, NULL)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_8_output, AI_STATIC,
  239, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &re_lu_8_output_array, NULL)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_9_output, AI_STATIC,
  240, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3840),
  1, &re_lu_9_output_array, NULL)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_output, AI_STATIC,
  241, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 40, 30), AI_STRIDE_INIT(4, 4, 4, 64, 2560),
  1, &re_lu_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_layer, 156,
  SM_TYPE, 0x0, NULL,
  sm, forward_sm,
  &dense_chain,
  NULL, &dense_layer, AI_STATIC, 
  .nl_params = NULL, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &global_average_pooling2d_pool_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_dense_weights, &dense_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_dense_layer, 156,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_dense_chain,
  NULL, &dense_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  global_average_pooling2d_pool_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &global_average_pooling2d_pool_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  global_average_pooling2d_pool_layer, 154,
  POOL_TYPE, 0x0, NULL,
  pool, forward_ap,
  &global_average_pooling2d_pool_chain,
  NULL, &dense_dense_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(3, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(3, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float re_lu_34_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_34_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_34_nl_params_data, re_lu_34_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_34_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_34_layer, 153,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_34_chain,
  NULL, &global_average_pooling2d_pool_layer, AI_STATIC, 
  .nl_params = &re_lu_34_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_34_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 152,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_34_chain,
  NULL, &re_lu_34_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_33_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 150,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_33_chain,
  NULL, &conv2d_34_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_33_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_33_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_33_nl_params_data, re_lu_33_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_33_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_33_layer, 148,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_33_chain,
  NULL, &conv2d_33_layer, AI_STATIC, 
  .nl_params = &re_lu_33_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_16_weights, &depthwise_conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_16_layer, 147,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_16_chain,
  NULL, &re_lu_33_layer, AI_STATIC, 
  .groups = 336, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_32_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_32_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_32_nl_params_data, re_lu_32_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_32_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_32_layer, 145,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_32_chain,
  NULL, &depthwise_conv2d_16_layer, AI_STATIC, 
  .nl_params = &re_lu_32_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_32_weights, &conv2d_32_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_32_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_32_layer, 144,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_32_chain,
  NULL, &re_lu_32_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_8_output, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_9_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_9_layer, 142,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_9_chain,
  NULL, &conv2d_32_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_31_weights, &conv2d_31_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_31_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_layer, 141,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_31_chain,
  NULL, &add_9_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_31_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_31_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_31_nl_params_data, re_lu_31_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_31_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_31_layer, 139,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_31_chain,
  NULL, &conv2d_31_layer, AI_STATIC, 
  .nl_params = &re_lu_31_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_15_weights, &depthwise_conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_15_layer, 138,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_15_chain,
  NULL, &re_lu_31_layer, AI_STATIC, 
  .groups = 336, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_30_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_30_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_30_nl_params_data, re_lu_30_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_30_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_30_layer, 136,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_30_chain,
  NULL, &depthwise_conv2d_15_layer, AI_STATIC, 
  .nl_params = &re_lu_30_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_30_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 135,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_30_chain,
  NULL, &re_lu_30_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_27_output, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_8_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_8_layer, 133,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_8_chain,
  NULL, &conv2d_30_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_29_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 132,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_29_chain,
  NULL, &add_8_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_29_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_29_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_29_nl_params_data, re_lu_29_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_29_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_29_layer, 130,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_29_chain,
  NULL, &conv2d_29_layer, AI_STATIC, 
  .nl_params = &re_lu_29_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_14_weights, &depthwise_conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_14_layer, 129,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_14_chain,
  NULL, &re_lu_29_layer, AI_STATIC, 
  .groups = 336, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_28_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_28_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_28_nl_params_data, re_lu_28_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_28_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_28_layer, 127,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_28_chain,
  NULL, &depthwise_conv2d_14_layer, AI_STATIC, 
  .nl_params = &re_lu_28_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_28_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 126,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_28_chain,
  NULL, &re_lu_28_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_27_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 124,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_27_chain,
  NULL, &conv2d_28_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_27_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_27_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_27_nl_params_data, re_lu_27_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_27_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_27_layer, 122,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_27_chain,
  NULL, &conv2d_27_layer, AI_STATIC, 
  .nl_params = &re_lu_27_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_13_weights, &depthwise_conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_13_layer, 119,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_13_chain,
  NULL, &re_lu_27_layer, AI_STATIC, 
  .groups = 192, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_26_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_26_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_26_nl_params_data, re_lu_26_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_26_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_26_layer, 118,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_26_chain,
  NULL, &depthwise_conv2d_13_layer, AI_STATIC, 
  .nl_params = &re_lu_26_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_26_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 117,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_26_chain,
  NULL, &re_lu_26_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_6_output, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_7_layer, 115,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_7_chain,
  NULL, &conv2d_26_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_25_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 114,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_25_chain,
  NULL, &add_7_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_25_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_25_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_25_nl_params_data, re_lu_25_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_25_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_25_layer, 112,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_25_chain,
  NULL, &conv2d_25_layer, AI_STATIC, 
  .nl_params = &re_lu_25_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_12_weights, &depthwise_conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_12_layer, 111,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_12_chain,
  NULL, &re_lu_25_layer, AI_STATIC, 
  .groups = 192, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_24_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_24_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_24_nl_params_data, re_lu_24_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_24_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_24_layer, 109,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_24_chain,
  NULL, &depthwise_conv2d_12_layer, AI_STATIC, 
  .nl_params = &re_lu_24_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_24_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 108,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_24_chain,
  NULL, &re_lu_24_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_output, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_6_layer, 106,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_6_chain,
  NULL, &conv2d_24_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_23_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 105,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_23_chain,
  NULL, &add_6_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_23_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_23_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_23_nl_params_data, re_lu_23_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_23_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_23_layer, 103,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_23_chain,
  NULL, &conv2d_23_layer, AI_STATIC, 
  .nl_params = &re_lu_23_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_11_weights, &depthwise_conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_11_layer, 102,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_11_chain,
  NULL, &re_lu_23_layer, AI_STATIC, 
  .groups = 192, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_22_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_22_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_22_nl_params_data, re_lu_22_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_22_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_22_layer, 100,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_22_chain,
  NULL, &depthwise_conv2d_11_layer, AI_STATIC, 
  .nl_params = &re_lu_22_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_22_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 99,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_22_chain,
  NULL, &re_lu_22_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 97,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_21_chain,
  NULL, &conv2d_22_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_21_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_21_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_21_nl_params_data, re_lu_21_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_21_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_21_layer, 95,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_21_chain,
  NULL, &conv2d_21_layer, AI_STATIC, 
  .nl_params = &re_lu_21_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_10_weights, &depthwise_conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_10_layer, 94,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_10_chain,
  NULL, &re_lu_21_layer, AI_STATIC, 
  .groups = 144, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_20_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_20_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_20_nl_params_data, re_lu_20_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_20_layer, 92,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_20_chain,
  NULL, &depthwise_conv2d_10_layer, AI_STATIC, 
  .nl_params = &re_lu_20_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_20_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 91,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_20_chain,
  NULL, &re_lu_20_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_4_output, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_5_layer, 89,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_5_chain,
  NULL, &conv2d_20_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_19_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 88,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_19_chain,
  NULL, &add_5_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_19_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_19_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_19_nl_params_data, re_lu_19_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_19_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_19_layer, 86,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_19_chain,
  NULL, &conv2d_19_layer, AI_STATIC, 
  .nl_params = &re_lu_19_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_9_weights, &depthwise_conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_9_layer, 85,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_9_chain,
  NULL, &re_lu_19_layer, AI_STATIC, 
  .groups = 144, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_18_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_18_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_18_nl_params_data, re_lu_18_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_18_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_18_layer, 83,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_18_chain,
  NULL, &depthwise_conv2d_9_layer, AI_STATIC, 
  .nl_params = &re_lu_18_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_18_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 82,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_18_chain,
  NULL, &re_lu_18_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_3_output, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_4_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_4_layer, 80,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_4_chain,
  NULL, &conv2d_18_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 79,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_17_chain,
  NULL, &add_4_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_17_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_17_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_17_nl_params_data, re_lu_17_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_17_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_17_layer, 77,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_17_chain,
  NULL, &conv2d_17_layer, AI_STATIC, 
  .nl_params = &re_lu_17_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_8_weights, &depthwise_conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_8_layer, 76,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_8_chain,
  NULL, &re_lu_17_layer, AI_STATIC, 
  .groups = 144, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_16_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_16_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_16_nl_params_data, re_lu_16_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_16_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_16_layer, 74,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_16_chain,
  NULL, &depthwise_conv2d_8_layer, AI_STATIC, 
  .nl_params = &re_lu_16_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 73,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_16_chain,
  NULL, &re_lu_16_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_13_output, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_3_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_3_layer, 71,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_3_chain,
  NULL, &conv2d_16_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 70,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_15_chain,
  NULL, &add_3_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_15_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_15_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_15_nl_params_data, re_lu_15_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_15_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_15_layer, 68,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_15_chain,
  NULL, &conv2d_15_layer, AI_STATIC, 
  .nl_params = &re_lu_15_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_7_weights, &depthwise_conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_7_layer, 67,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_7_chain,
  NULL, &re_lu_15_layer, AI_STATIC, 
  .groups = 144, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_14_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_14_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_14_nl_params_data, re_lu_14_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_14_layer, 65,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_14_chain,
  NULL, &depthwise_conv2d_7_layer, AI_STATIC, 
  .nl_params = &re_lu_14_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_14_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 64,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_14_chain,
  NULL, &re_lu_14_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_13_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 62,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_13_chain,
  NULL, &conv2d_14_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_13_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_13_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_13_nl_params_data, re_lu_13_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_13_layer, 60,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_13_chain,
  NULL, &conv2d_13_layer, AI_STATIC, 
  .nl_params = &re_lu_13_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_6_weights, &depthwise_conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_6_layer, 57,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_6_chain,
  NULL, &re_lu_13_layer, AI_STATIC, 
  .groups = 96, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_12_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_12_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_12_nl_params_data, re_lu_12_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_12_layer, 56,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_12_chain,
  NULL, &depthwise_conv2d_6_layer, AI_STATIC, 
  .nl_params = &re_lu_12_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_12_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 55,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_12_chain,
  NULL, &re_lu_12_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_1_output, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_2_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_2_layer, 53,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_2_chain,
  NULL, &conv2d_12_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_11_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 52,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_11_chain,
  NULL, &add_2_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_11_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_11_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_11_nl_params_data, re_lu_11_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_11_layer, 50,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_11_chain,
  NULL, &conv2d_11_layer, AI_STATIC, 
  .nl_params = &re_lu_11_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_5_weights, &depthwise_conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_5_layer, 49,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_5_chain,
  NULL, &re_lu_11_layer, AI_STATIC, 
  .groups = 96, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_10_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_10_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_10_nl_params_data, re_lu_10_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_10_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_10_layer, 47,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_10_chain,
  NULL, &depthwise_conv2d_5_layer, AI_STATIC, 
  .nl_params = &re_lu_10_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_10_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 46,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_10_chain,
  NULL, &re_lu_10_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_output, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_1_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_1_layer, 44,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_1_chain,
  NULL, &conv2d_10_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_9_chain,
  NULL, &add_1_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_9_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_9_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_9_nl_params_data, re_lu_9_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_9_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_9_layer, 41,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_9_chain,
  NULL, &conv2d_9_layer, AI_STATIC, 
  .nl_params = &re_lu_9_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_4_weights, &depthwise_conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_4_layer, 40,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_4_chain,
  NULL, &re_lu_9_layer, AI_STATIC, 
  .groups = 96, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_8_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_8_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_8_nl_params_data, re_lu_8_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_8_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_8_layer, 38,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_8_chain,
  NULL, &depthwise_conv2d_4_layer, AI_STATIC, 
  .nl_params = &re_lu_8_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 37,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_8_chain,
  NULL, &re_lu_8_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 35,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_7_chain,
  NULL, &conv2d_8_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_7_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_7_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_7_nl_params_data, re_lu_7_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_7_layer, 33,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_7_chain,
  NULL, &conv2d_7_layer, AI_STATIC, 
  .nl_params = &re_lu_7_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_3_weights, &depthwise_conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_3_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_3_chain,
  NULL, &re_lu_7_layer, AI_STATIC, 
  .groups = 48, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 0, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_6_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_6_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_6_nl_params_data, re_lu_6_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_6_layer, 29,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_6_chain,
  NULL, &depthwise_conv2d_3_layer, AI_STATIC, 
  .nl_params = &re_lu_6_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_6_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_6_chain,
  NULL, &re_lu_6_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_output, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_layer, 26,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &add_chain,
  NULL, &conv2d_6_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_5_chain,
  NULL, &add_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_5_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_5_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_5_nl_params_data, re_lu_5_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_5_layer, 23,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_5_chain,
  NULL, &conv2d_5_layer, AI_STATIC, 
  .nl_params = &re_lu_5_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_2_weights, &depthwise_conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_2_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_2_chain,
  NULL, &re_lu_5_layer, AI_STATIC, 
  .groups = 48, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_4_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_4_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_4_nl_params_data, re_lu_4_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_4_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_4_layer, 20,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_4_chain,
  NULL, &depthwise_conv2d_2_layer, AI_STATIC, 
  .nl_params = &re_lu_4_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_4_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_4_chain,
  NULL, &re_lu_4_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_3_chain,
  NULL, &conv2d_4_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_3_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_3_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_3_nl_params_data, re_lu_3_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_3_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_3_layer, 15,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_3_chain,
  NULL, &conv2d_3_layer, AI_STATIC, 
  .nl_params = &re_lu_3_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_1_weights, &depthwise_conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_1_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_1_chain,
  NULL, &re_lu_3_layer, AI_STATIC, 
  .groups = 48, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_2_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_2_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_2_nl_params_data, re_lu_2_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_2_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_2_layer, 11,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_2_chain,
  NULL, &depthwise_conv2d_1_layer, AI_STATIC, 
  .nl_params = &re_lu_2_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_2_chain,
  NULL, &re_lu_2_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_1_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_1_chain,
  NULL, &conv2d_2_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_1_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_1_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_1_nl_params_data, re_lu_1_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_1_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_1_layer, 6,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_1_chain,
  NULL, &conv2d_1_layer, AI_STATIC, 
  .nl_params = &re_lu_1_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_weights, &depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_if32of32wf32,
  &depthwise_conv2d_chain,
  NULL, &re_lu_1_layer, AI_STATIC, 
  .groups = 16, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float re_lu_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    re_lu_nl_params, AI_ARRAY_FORMAT_FLOAT,
    re_lu_nl_params_data, re_lu_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_layer, 3,
  NL_TYPE, 0x0, NULL,
  nl, forward_clip,
  &re_lu_chain,
  NULL, &depthwise_conv2d_layer, AI_STATIC, 
  .nl_params = &re_lu_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_weights, &conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_chain,
  NULL, &re_lu_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1571724, 1, 1),
    1571724, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 248544, 1, 1),
    248544, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_CIFAR10_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_CIFAR10_OUT_NUM, &dense_output),
  &conv2d_layer, 0xaed8b49f, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1571724, 1, 1),
      1571724, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 248544, 1, 1),
      248544, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_CIFAR10_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_CIFAR10_OUT_NUM, &dense_output),
  &conv2d_layer, 0xaed8b49f, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_cifar10_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_cifar10_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_1_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 114004);
    input_1_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 114004);
    conv2d_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 171604);
    conv2d_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 171604);
    conv2d_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 171712);
    conv2d_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 171712);
    re_lu_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 171712);
    re_lu_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 171712);
    depthwise_conv2d_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 94912);
    depthwise_conv2d_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 94912);
    re_lu_1_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 94912);
    re_lu_1_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 94912);
    conv2d_1_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 171712);
    conv2d_1_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 171712);
    conv2d_1_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 210112);
    conv2d_1_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 210112);
    conv2d_2_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 248512);
    conv2d_2_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 248512);
    conv2d_2_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 4032);
    conv2d_2_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 4032);
    re_lu_2_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 4032);
    re_lu_2_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 4032);
    depthwise_conv2d_1_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    depthwise_conv2d_1_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    re_lu_3_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 57600);
    re_lu_3_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 57600);
    conv2d_3_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_3_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_3_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 192);
    conv2d_3_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 192);
    conv2d_4_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_4_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_4_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 9792);
    conv2d_4_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 9792);
    re_lu_4_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 67392);
    re_lu_4_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 67392);
    depthwise_conv2d_2_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 9792);
    depthwise_conv2d_2_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 9792);
    re_lu_5_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 67392);
    re_lu_5_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 67392);
    conv2d_5_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_5_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_5_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 9792);
    conv2d_5_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 9792);
    add_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 19392);
    add_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 19392);
    conv2d_6_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_6_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_6_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 28992);
    conv2d_6_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 28992);
    re_lu_6_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 86592);
    re_lu_6_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 86592);
    depthwise_conv2d_3_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    depthwise_conv2d_3_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    re_lu_7_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 15360);
    re_lu_7_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 15360);
    conv2d_7_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_7_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_7_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 192);
    conv2d_7_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 192);
    conv2d_8_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_8_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_8_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 5312);
    conv2d_8_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 5312);
    re_lu_8_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 36032);
    re_lu_8_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 36032);
    depthwise_conv2d_4_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 5312);
    depthwise_conv2d_4_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 5312);
    re_lu_9_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 36032);
    re_lu_9_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 36032);
    conv2d_9_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 5312);
    conv2d_9_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 5312);
    conv2d_9_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 5696);
    conv2d_9_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 5696);
    add_1_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 10816);
    add_1_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 10816);
    conv2d_10_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_10_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 15936);
    conv2d_10_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 15936);
    re_lu_10_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 46656);
    re_lu_10_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 46656);
    depthwise_conv2d_5_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 15936);
    depthwise_conv2d_5_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 15936);
    re_lu_11_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 46656);
    re_lu_11_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 46656);
    conv2d_11_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_11_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_11_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 384);
    conv2d_11_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 384);
    add_2_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 5504);
    add_2_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 5504);
    conv2d_12_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_12_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_12_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 10624);
    conv2d_12_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 10624);
    re_lu_12_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 41344);
    re_lu_12_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 41344);
    depthwise_conv2d_6_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    depthwise_conv2d_6_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    re_lu_13_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 7680);
    re_lu_13_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 7680);
    conv2d_13_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_13_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_13_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 384);
    conv2d_13_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 384);
    conv2d_14_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_14_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_14_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2304);
    conv2d_14_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2304);
    re_lu_14_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 13824);
    re_lu_14_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 13824);
    depthwise_conv2d_7_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2304);
    depthwise_conv2d_7_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2304);
    re_lu_15_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 13824);
    re_lu_15_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 13824);
    conv2d_15_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2304);
    conv2d_15_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2304);
    conv2d_15_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2880);
    conv2d_15_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2880);
    add_3_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 4800);
    add_3_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 4800);
    conv2d_16_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_16_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 6720);
    conv2d_16_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 6720);
    re_lu_16_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 18240);
    re_lu_16_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 18240);
    depthwise_conv2d_8_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 6720);
    depthwise_conv2d_8_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 6720);
    re_lu_17_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 18240);
    re_lu_17_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 18240);
    conv2d_17_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_17_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_17_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 576);
    conv2d_17_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 576);
    add_4_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2496);
    add_4_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2496);
    conv2d_18_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_18_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_18_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 4416);
    conv2d_18_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 4416);
    re_lu_18_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 15936);
    re_lu_18_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 15936);
    depthwise_conv2d_9_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 4416);
    depthwise_conv2d_9_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 4416);
    re_lu_19_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 15936);
    re_lu_19_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 15936);
    conv2d_19_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_19_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_19_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 576);
    conv2d_19_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 576);
    add_5_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 4416);
    add_5_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 4416);
    conv2d_20_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_20_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_20_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 6336);
    conv2d_20_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 6336);
    re_lu_20_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 17856);
    re_lu_20_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 17856);
    depthwise_conv2d_10_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    depthwise_conv2d_10_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    re_lu_21_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 11520);
    re_lu_21_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 11520);
    conv2d_21_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_21_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 576);
    conv2d_21_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 576);
    conv2d_22_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_22_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3136);
    conv2d_22_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3136);
    re_lu_22_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 18496);
    re_lu_22_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 18496);
    depthwise_conv2d_11_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3136);
    depthwise_conv2d_11_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3136);
    re_lu_23_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 18496);
    re_lu_23_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 18496);
    conv2d_23_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3136);
    conv2d_23_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3136);
    conv2d_23_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3904);
    conv2d_23_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3904);
    add_6_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 6464);
    add_6_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 6464);
    conv2d_24_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_24_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_24_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 9024);
    conv2d_24_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 9024);
    re_lu_24_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 24384);
    re_lu_24_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 24384);
    depthwise_conv2d_12_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 9024);
    depthwise_conv2d_12_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 9024);
    re_lu_25_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 24384);
    re_lu_25_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 24384);
    conv2d_25_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_25_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_25_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 768);
    conv2d_25_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 768);
    add_7_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3328);
    add_7_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3328);
    conv2d_26_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_26_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_26_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 5888);
    conv2d_26_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 5888);
    re_lu_26_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 21248);
    re_lu_26_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 21248);
    depthwise_conv2d_13_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    depthwise_conv2d_13_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    re_lu_27_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 4608);
    re_lu_27_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 4608);
    conv2d_27_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_27_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 768);
    conv2d_27_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 768);
    conv2d_28_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_28_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2112);
    conv2d_28_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2112);
    re_lu_28_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 10176);
    re_lu_28_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 10176);
    depthwise_conv2d_14_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2112);
    depthwise_conv2d_14_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2112);
    re_lu_29_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 10176);
    re_lu_29_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 10176);
    conv2d_29_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2112);
    conv2d_29_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2112);
    conv2d_29_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3456);
    conv2d_29_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3456);
    add_8_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 2112);
    add_8_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 2112);
    conv2d_30_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_30_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_30_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3456);
    conv2d_30_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3456);
    re_lu_30_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 11520);
    re_lu_30_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 11520);
    depthwise_conv2d_15_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3456);
    depthwise_conv2d_15_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3456);
    re_lu_31_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 11520);
    re_lu_31_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 11520);
    conv2d_31_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_31_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_31_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 3456);
    conv2d_31_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 3456);
    add_9_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    add_9_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_32_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 1344);
    conv2d_32_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 1344);
    conv2d_32_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 1568);
    conv2d_32_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 1568);
    re_lu_32_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 9632);
    re_lu_32_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 9632);
    depthwise_conv2d_16_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    depthwise_conv2d_16_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    re_lu_33_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 8064);
    re_lu_33_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 8064);
    conv2d_33_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_33_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 1344);
    conv2d_33_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 1344);
    conv2d_34_scratch0_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_34_scratch0_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    conv2d_34_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 4032);
    conv2d_34_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 4032);
    re_lu_34_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 34752);
    re_lu_34_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 34752);
    global_average_pooling2d_pool_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    global_average_pooling2d_pool_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    dense_dense_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 5120);
    dense_dense_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 5120);
    dense_output_array.data = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    dense_output_array.data_start = AI_PTR(g_network_cifar10_activations_map[0] + 0);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_cifar10_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_cifar10_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 0);
    conv2d_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 0);
    conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 1728);
    conv2d_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 1728);
    depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 1792);
    depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 1792);
    depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 2368);
    depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 2368);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 2432);
    conv2d_1_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 2432);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 2944);
    conv2d_1_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 2944);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 2976);
    conv2d_2_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 2976);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 4512);
    conv2d_2_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 4512);
    depthwise_conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_1_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 4704);
    depthwise_conv2d_1_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 4704);
    depthwise_conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_1_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 6432);
    depthwise_conv2d_1_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 6432);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 6624);
    conv2d_3_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 6624);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 8160);
    conv2d_3_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 8160);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 8192);
    conv2d_4_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 8192);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 9728);
    conv2d_4_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 9728);
    depthwise_conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_2_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 9920);
    depthwise_conv2d_2_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 9920);
    depthwise_conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_2_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 11648);
    depthwise_conv2d_2_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 11648);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 11840);
    conv2d_5_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 11840);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 13376);
    conv2d_5_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 13376);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 13408);
    conv2d_6_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 13408);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 14944);
    conv2d_6_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 14944);
    depthwise_conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_3_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 15136);
    depthwise_conv2d_3_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 15136);
    depthwise_conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_3_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 16864);
    depthwise_conv2d_3_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 16864);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 17056);
    conv2d_7_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 17056);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 20128);
    conv2d_7_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 20128);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 20192);
    conv2d_8_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 20192);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 26336);
    conv2d_8_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 26336);
    depthwise_conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_4_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 26720);
    depthwise_conv2d_4_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 26720);
    depthwise_conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_4_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 30176);
    depthwise_conv2d_4_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 30176);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 30560);
    conv2d_9_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 30560);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 36704);
    conv2d_9_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 36704);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 36768);
    conv2d_10_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 36768);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 42912);
    conv2d_10_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 42912);
    depthwise_conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_5_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 43296);
    depthwise_conv2d_5_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 43296);
    depthwise_conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_5_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 46752);
    depthwise_conv2d_5_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 46752);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 47136);
    conv2d_11_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 47136);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 53280);
    conv2d_11_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 53280);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 53344);
    conv2d_12_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 53344);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 59488);
    conv2d_12_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 59488);
    depthwise_conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_6_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 59872);
    depthwise_conv2d_6_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 59872);
    depthwise_conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_6_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 63328);
    depthwise_conv2d_6_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 63328);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 63712);
    conv2d_13_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 63712);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 72928);
    conv2d_13_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 72928);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 73024);
    conv2d_14_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 73024);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 86848);
    conv2d_14_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 86848);
    depthwise_conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_7_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 87424);
    depthwise_conv2d_7_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 87424);
    depthwise_conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_7_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 92608);
    depthwise_conv2d_7_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 92608);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 93184);
    conv2d_15_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 93184);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 107008);
    conv2d_15_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 107008);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 107104);
    conv2d_16_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 107104);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 120928);
    conv2d_16_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 120928);
    depthwise_conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_8_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 121504);
    depthwise_conv2d_8_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 121504);
    depthwise_conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_8_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 126688);
    depthwise_conv2d_8_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 126688);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 127264);
    conv2d_17_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 127264);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 141088);
    conv2d_17_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 141088);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 141184);
    conv2d_18_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 141184);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 155008);
    conv2d_18_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 155008);
    depthwise_conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_9_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 155584);
    depthwise_conv2d_9_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 155584);
    depthwise_conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_9_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 160768);
    depthwise_conv2d_9_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 160768);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 161344);
    conv2d_19_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 161344);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 175168);
    conv2d_19_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 175168);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 175264);
    conv2d_20_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 175264);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 189088);
    conv2d_20_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 189088);
    depthwise_conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_10_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 189664);
    depthwise_conv2d_10_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 189664);
    depthwise_conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_10_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 194848);
    depthwise_conv2d_10_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 194848);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 195424);
    conv2d_21_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 195424);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 213856);
    conv2d_21_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 213856);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 213984);
    conv2d_22_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 213984);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 238560);
    conv2d_22_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 238560);
    depthwise_conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_11_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 239328);
    depthwise_conv2d_11_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 239328);
    depthwise_conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_11_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 246240);
    depthwise_conv2d_11_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 246240);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 247008);
    conv2d_23_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 247008);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 271584);
    conv2d_23_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 271584);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 271712);
    conv2d_24_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 271712);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 296288);
    conv2d_24_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 296288);
    depthwise_conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_12_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 297056);
    depthwise_conv2d_12_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 297056);
    depthwise_conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_12_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 303968);
    depthwise_conv2d_12_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 303968);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 304736);
    conv2d_25_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 304736);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 329312);
    conv2d_25_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 329312);
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 329440);
    conv2d_26_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 329440);
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 354016);
    conv2d_26_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 354016);
    depthwise_conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_13_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 354784);
    depthwise_conv2d_13_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 354784);
    depthwise_conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_13_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 361696);
    depthwise_conv2d_13_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 361696);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 362464);
    conv2d_27_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 362464);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 405472);
    conv2d_27_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 405472);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 405696);
    conv2d_28_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 405696);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 480960);
    conv2d_28_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 480960);
    depthwise_conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_14_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 482304);
    depthwise_conv2d_14_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 482304);
    depthwise_conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_14_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 494400);
    depthwise_conv2d_14_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 494400);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 495744);
    conv2d_29_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 495744);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 571008);
    conv2d_29_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 571008);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 571232);
    conv2d_30_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 571232);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 646496);
    conv2d_30_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 646496);
    depthwise_conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_15_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 647840);
    depthwise_conv2d_15_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 647840);
    depthwise_conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_15_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 659936);
    depthwise_conv2d_15_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 659936);
    conv2d_31_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 661280);
    conv2d_31_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 661280);
    conv2d_31_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 736544);
    conv2d_31_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 736544);
    conv2d_32_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 736768);
    conv2d_32_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 736768);
    conv2d_32_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 812032);
    conv2d_32_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 812032);
    depthwise_conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_16_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 813376);
    depthwise_conv2d_16_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 813376);
    depthwise_conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_16_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 825472);
    depthwise_conv2d_16_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 825472);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 826816);
    conv2d_33_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 826816);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 977344);
    conv2d_33_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 977344);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 977792);
    conv2d_34_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 977792);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 1551232);
    conv2d_34_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 1551232);
    dense_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_dense_weights_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 1556352);
    dense_dense_weights_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 1556352);
    dense_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_dense_bias_array.data = AI_PTR(g_network_cifar10_weights_map[0] + 1571712);
    dense_dense_bias_array.data_start = AI_PTR(g_network_cifar10_weights_map[0] + 1571712);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_cifar10_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_CIFAR10_MODEL_NAME,
      .model_signature   = AI_NETWORK_CIFAR10_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 6629360,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0xaed8b49f,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_network_cifar10_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_CIFAR10_MODEL_NAME,
      .model_signature   = AI_NETWORK_CIFAR10_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 6629360,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0xaed8b49f,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_network_cifar10_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_network_cifar10_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_network_cifar10_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_network_cifar10_create(network, AI_NETWORK_CIFAR10_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_network_cifar10_data_params_get(&params) != true) {
    err = ai_network_cifar10_get_error(*network);
    return err;
  }
#if defined(AI_NETWORK_CIFAR10_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_NETWORK_CIFAR10_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_network_cifar10_init(*network, &params) != true) {
    err = ai_network_cifar10_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_network_cifar10_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_network_cifar10_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_network_cifar10_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_network_cifar10_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= network_cifar10_configure_weights(net_ctx, params);
  ok &= network_cifar10_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_cifar10_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_network_cifar10_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_CIFAR10_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

