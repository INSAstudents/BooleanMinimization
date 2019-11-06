#include <cstdint>

const uint8_t Midori128_S0[256] = {
	0x11, 0x10, 0x51, 0x50, 0xb4, 0x30, 0xf4, 0x70, 0x59, 0x58, 0x19, 0x18, 0xfc, 0x78, 0xbc, 0x38,
	0x01, 0x00, 0x13, 0x12, 0xa4, 0x20, 0xb6, 0x32, 0x0b, 0x0a, 0x1b, 0x1a, 0xae, 0x2a, 0xbe, 0x3a,
	0x15, 0x31, 0x55, 0x71, 0xb5, 0x35, 0xf5, 0x75, 0x5d, 0x79, 0x1d, 0x39, 0xfd, 0x7d, 0xbd, 0x3d,
	0x05, 0x21, 0x17, 0x33, 0xa5, 0x25, 0xb7, 0x37, 0x0f, 0x2b, 0x1f, 0x3b, 0xaf, 0x2f, 0xbf, 0x3f,
	0x4b, 0x4a, 0x5b, 0x5a, 0xee, 0x6a, 0xfe, 0x7a, 0x49, 0x48, 0x41, 0x40, 0xec, 0x68, 0xe4, 0x60,
	0x03, 0x02, 0x53, 0x52, 0xa6, 0x22, 0xf6, 0x72, 0x09, 0x08, 0x43, 0x42, 0xac, 0x28, 0xe6, 0x62,
	0x4f, 0x6b, 0x5f, 0x7b, 0xef, 0x6f, 0xff, 0x7f, 0x4d, 0x69, 0x45, 0x61, 0xed, 0x6d, 0xe5, 0x65,
	0x07, 0x23, 0x57, 0x73, 0xa7, 0x27, 0xf7, 0x77, 0x0d, 0x29, 0x47, 0x63, 0xad, 0x2d, 0xe7, 0x67,
	0x95, 0xb0, 0xd5, 0xf0, 0x94, 0x90, 0xd4, 0xd0, 0xdd, 0xf8, 0x9d, 0xb8, 0xdc, 0xd8, 0x9c, 0x98,
	0x85, 0xa0, 0x97, 0xb2, 0x84, 0x80, 0x96, 0x92, 0x8f, 0xaa, 0x9f, 0xba, 0x8e, 0x8a, 0x9e, 0x9a,
	0x91, 0xb1, 0xd1, 0xf1, 0x14, 0x34, 0x54, 0x74, 0xd9, 0xf9, 0x99, 0xb9, 0x5c, 0x7c, 0x1c, 0x3c,
	0x81, 0xa1, 0x93, 0xb3, 0x04, 0x24, 0x16, 0x36, 0x8b, 0xab, 0x9b, 0xbb, 0x0e, 0x2e, 0x1e, 0x3e,
	0xcf, 0xea, 0xdf, 0xfa, 0xce, 0xca, 0xde, 0xda, 0xcd, 0xe8, 0xc5, 0xe0, 0xcc, 0xc8, 0xc4, 0xc0,
	0x87, 0xa2, 0xd7, 0xf2, 0x86, 0x82, 0xd6, 0xd2, 0x8d, 0xa8, 0xc7, 0xe2, 0x8c, 0x88, 0xc6, 0xc2,
	0xcb, 0xeb, 0xdb, 0xfb, 0x4e, 0x6e, 0x5e, 0x7e, 0xc9, 0xe9, 0xc1, 0xe1, 0x4c, 0x6c, 0x44, 0x64,
	0x83, 0xa3, 0xd3, 0xf3, 0x06, 0x26, 0x56, 0x76, 0x89, 0xa9, 0xc3, 0xe3, 0x0c, 0x2c, 0x46, 0x66,
};

const uint8_t Midori128_S1[256] = {
	0x88, 0x8a, 0x4b, 0xcb, 0xac, 0xae, 0x6f, 0xef, 0x80, 0x82, 0x43, 0xc3, 0x94, 0x96, 0x57, 0xd7,
	0xa8, 0xaa, 0x6b, 0xeb, 0x8c, 0x8e, 0x4f, 0xcf, 0x98, 0x9a, 0x5b, 0xdb, 0x9c, 0x9e, 0x5f, 0xdf,
	0xb4, 0xb6, 0x77, 0xf7, 0xa4, 0xa6, 0x67, 0xe7, 0x90, 0x92, 0x53, 0xd3, 0x84, 0x86, 0x47, 0xc7,
	0xbc, 0xbe, 0x7f, 0xff, 0xa0, 0xa2, 0x63, 0xe3, 0xb8, 0xba, 0x7b, 0xfb, 0xb0, 0xb2, 0x73, 0xf3,
	0xca, 0xc8, 0x4a, 0x0a, 0xee, 0xec, 0x6e, 0x2e, 0xc2, 0xc0, 0x42, 0x02, 0xd6, 0xd4, 0x56, 0x16,
	0xea, 0xe8, 0x6a, 0x2a, 0xce, 0xcc, 0x4e, 0x0e, 0xda, 0xd8, 0x5a, 0x1a, 0xde, 0xdc, 0x5e, 0x1e,
	0xf6, 0xf4, 0x76, 0x36, 0xe6, 0xe4, 0x66, 0x26, 0xd2, 0xd0, 0x52, 0x12, 0xc6, 0xc4, 0x46, 0x06,
	0xfe, 0xfc, 0x7e, 0x3e, 0xe2, 0xe0, 0x62, 0x22, 0xfa, 0xf8, 0x7a, 0x3a, 0xf2, 0xf0, 0x72, 0x32,
	0x08, 0x89, 0x09, 0x8b, 0x2c, 0xad, 0x2d, 0xaf, 0x00, 0x81, 0x01, 0x83, 0x14, 0x95, 0x15, 0x97,
	0x28, 0xa9, 0x29, 0xab, 0x0c, 0x8d, 0x0d, 0x8f, 0x18, 0x99, 0x19, 0x9b, 0x1c, 0x9d, 0x1d, 0x9f,
	0x34, 0xb5, 0x35, 0xb7, 0x24, 0xa5, 0x25, 0xa7, 0x10, 0x91, 0x11, 0x93, 0x04, 0x85, 0x05, 0x87,
	0x3c, 0xbd, 0x3d, 0xbf, 0x20, 0xa1, 0x21, 0xa3, 0x38, 0xb9, 0x39, 0xbb, 0x30, 0xb1, 0x31, 0xb3,
	0x49, 0xc9, 0x48, 0x0b, 0x6d, 0xed, 0x6c, 0x2f, 0x41, 0xc1, 0x40, 0x03, 0x55, 0xd5, 0x54, 0x17,
	0x69, 0xe9, 0x68, 0x2b, 0x4d, 0xcd, 0x4c, 0x0f, 0x59, 0xd9, 0x58, 0x1b, 0x5d, 0xdd, 0x5c, 0x1f,
	0x75, 0xf5, 0x74, 0x37, 0x65, 0xe5, 0x64, 0x27, 0x51, 0xd1, 0x50, 0x13, 0x45, 0xc5, 0x44, 0x07,
	0x7d, 0xfd, 0x7c, 0x3f, 0x61, 0xe1, 0x60, 0x23, 0x79, 0xf9, 0x78, 0x3b, 0x71, 0xf1, 0x70, 0x33,
};

const uint8_t Midori128_S2[256] = {
	0x44, 0xc3, 0x47, 0x43, 0x40, 0xc0, 0xc2, 0x42, 0x54, 0xd3, 0x57, 0x53, 0x50, 0xd0, 0xd2, 0x52,
	0x3c, 0xbb, 0x3f, 0x3b, 0x38, 0xb8, 0xba, 0x3a, 0x7c, 0xfb, 0x7f, 0x7b, 0x78, 0xf8, 0xfa, 0x7a,
	0x74, 0xf3, 0x77, 0x73, 0x70, 0xf0, 0xf2, 0x72, 0x64, 0xe3, 0x67, 0x63, 0x60, 0xe0, 0xe2, 0x62,
	0x34, 0xb3, 0x37, 0x33, 0x30, 0xb0, 0xb2, 0x32, 0x14, 0x93, 0x17, 0x13, 0x10, 0x90, 0x92, 0x12,
	0x04, 0x83, 0x07, 0x03, 0x00, 0x80, 0x82, 0x02, 0x4c, 0xcb, 0x4f, 0x4b, 0x48, 0xc8, 0xca, 0x4a,
	0x0c, 0x8b, 0x0f, 0x0b, 0x08, 0x88, 0x8a, 0x0a, 0x5c, 0xdb, 0x5f, 0x5b, 0x58, 0xd8, 0xda, 0x5a,
	0x2c, 0xab, 0x2f, 0x2b, 0x28, 0xa8, 0xaa, 0x2a, 0x6c, 0xeb, 0x6f, 0x6b, 0x68, 0xe8, 0xea, 0x6a,
	0x24, 0xa3, 0x27, 0x23, 0x20, 0xa0, 0xa2, 0x22, 0x1c, 0x9b, 0x1f, 0x1b, 0x18, 0x98, 0x9a, 0x1a,
	0x45, 0xc7, 0x46, 0x41, 0xc4, 0xc5, 0xc6, 0xc1, 0x55, 0xd7, 0x56, 0x51, 0xd4, 0xd5, 0xd6, 0xd1,
	0x3d, 0xbf, 0x3e, 0x39, 0xbc, 0xbd, 0xbe, 0xb9, 0x7d, 0xff, 0x7e, 0x79, 0xfc, 0xfd, 0xfe, 0xf9,
	0x75, 0xf7, 0x76, 0x71, 0xf4, 0xf5, 0xf6, 0xf1, 0x65, 0xe7, 0x66, 0x61, 0xe4, 0xe5, 0xe6, 0xe1,
	0x35, 0xb7, 0x36, 0x31, 0xb4, 0xb5, 0xb6, 0xb1, 0x15, 0x97, 0x16, 0x11, 0x94, 0x95, 0x96, 0x91,
	0x05, 0x87, 0x06, 0x01, 0x84, 0x85, 0x86, 0x81, 0x4d, 0xcf, 0x4e, 0x49, 0xcc, 0xcd, 0xce, 0xc9,
	0x0d, 0x8f, 0x0e, 0x09, 0x8c, 0x8d, 0x8e, 0x89, 0x5d, 0xdf, 0x5e, 0x59, 0xdc, 0xdd, 0xde, 0xd9,
	0x2d, 0xaf, 0x2e, 0x29, 0xac, 0xad, 0xae, 0xa9, 0x6d, 0xef, 0x6e, 0x69, 0xec, 0xed, 0xee, 0xe9,
	0x25, 0xa7, 0x26, 0x21, 0xa4, 0xa5, 0xa6, 0xa1, 0x1d, 0x9f, 0x1e, 0x19, 0x9c, 0x9d, 0x9e, 0x99,
};

const uint8_t Midori128_S3[256] = {
	0x22, 0x2b, 0x20, 0x29, 0xa2, 0xab, 0x26, 0x2f, 0x4b, 0x0b, 0x49, 0x09, 0xcb, 0x8b, 0x4f, 0x0f,
	0xb2, 0xbb, 0x34, 0x3d, 0x32, 0x3b, 0x36, 0x3f, 0xdb, 0x9b, 0x5d, 0x1d, 0x5b, 0x1b, 0x5f, 0x1f,
	0x02, 0x43, 0x00, 0x41, 0x82, 0xc3, 0x06, 0x47, 0x42, 0x03, 0x40, 0x01, 0xc2, 0x83, 0x46, 0x07,
	0x92, 0xd3, 0x14, 0x55, 0x12, 0x53, 0x16, 0x57, 0xd2, 0x93, 0x54, 0x15, 0x52, 0x13, 0x56, 0x17,
	0x2a, 0x23, 0x28, 0x21, 0xaa, 0xa3, 0x2e, 0x27, 0x6b, 0x0a, 0x69, 0x08, 0xeb, 0x8a, 0x6f, 0x0e,
	0xba, 0xb3, 0x3c, 0x35, 0x3a, 0x33, 0x3e, 0x37, 0xfb, 0x9a, 0x7d, 0x1c, 0x7b, 0x1a, 0x7f, 0x1e,
	0x62, 0x63, 0x60, 0x61, 0xe2, 0xe3, 0x66, 0x67, 0x6a, 0x4a, 0x68, 0x48, 0xea, 0xca, 0x6e, 0x4e,
	0xf2, 0xf3, 0x74, 0x75, 0x72, 0x73, 0x76, 0x77, 0xfa, 0xda, 0x7c, 0x5c, 0x7a, 0x5a, 0x7e, 0x5e,
	0xb4, 0xbd, 0x24, 0x2d, 0xb6, 0xbf, 0xa6, 0xaf, 0xdd, 0x9d, 0x4d, 0x0d, 0xdf, 0x9f, 0xcf, 0x8f,
	0xb0, 0xb9, 0x30, 0x39, 0xa0, 0xa9, 0xa4, 0xad, 0xd9, 0x99, 0x59, 0x19, 0xc9, 0x89, 0xcd, 0x8d,
	0x94, 0xd5, 0x04, 0x45, 0x96, 0xd7, 0x86, 0xc7, 0xd4, 0x95, 0x44, 0x05, 0xd6, 0x97, 0xc6, 0x87,
	0x90, 0xd1, 0x10, 0x51, 0x80, 0xc1, 0x84, 0xc5, 0xd0, 0x91, 0x50, 0x11, 0xc0, 0x81, 0xc4, 0x85,
	0xbc, 0xb5, 0x2c, 0x25, 0xbe, 0xb7, 0xae, 0xa7, 0xfd, 0x9c, 0x6d, 0x0c, 0xff, 0x9e, 0xef, 0x8e,
	0xb8, 0xb1, 0x38, 0x31, 0xa8, 0xa1, 0xac, 0xa5, 0xf9, 0x98, 0x79, 0x18, 0xe9, 0x88, 0xed, 0x8c,
	0xf4, 0xf5, 0x64, 0x65, 0xf6, 0xf7, 0xe6, 0xe7, 0xfc, 0xdc, 0x6c, 0x4c, 0xfe, 0xde, 0xee, 0xce,
	0xf0, 0xf1, 0x70, 0x71, 0xe0, 0xe1, 0xe4, 0xe5, 0xf8, 0xd8, 0x78, 0x58, 0xe8, 0xc8, 0xec, 0xcc,
};
