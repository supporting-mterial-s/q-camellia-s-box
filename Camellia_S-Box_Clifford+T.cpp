#include<stdio.h>
#include<iostream>
#include <iomanip>
using namespace std;
int sbox[256] = {
112,130, 44,236,179, 39,192,229,228,133, 87, 53,234, 12,174, 65,
 35,239,107,147, 69, 25,165, 33,237, 14, 79, 78, 29,101,146,189,
134,184,175,143,124,235, 31,206, 62, 48,220, 95, 94,197, 11, 26,
166,225, 57,202,213, 71, 93, 61,217,  1, 90,214, 81, 86,108, 77,
139, 13,154,102,251,204,176, 45,116, 18, 43, 32,240,177,132,153,
223, 76,203,194, 52,126,118,  5,109,183,169, 49,209, 23,  4,215,
 20, 88, 58, 97,222, 27, 17, 28, 50, 15,156, 22, 83, 24,242, 34,
254, 68,207,178,195,181,122,145, 36,  8,232,168, 96,252,105, 80,
170,208,160,125,161,137, 98,151, 84, 91, 30,149,224,255,100,210,
 16,196,  0, 72,163,247,117,219,138,  3,230,218,  9, 63,221,148,
135, 92,131,  2,205, 74,144, 51,115,103,246,243,157,127,191,226,
 82,155,216, 38,200, 55,198, 59,129,150,111, 75, 19,190, 99, 46,
233,121,167,140,159,110,188,142, 41,245,249,182, 47,253,180, 89,
120,152,  6,106,231, 70,113,186,212, 37,171, 66,136,162,141,250,
114,  7,185, 85,248,238,172, 10, 54, 73, 42,104, 60, 56,241,164,
 64, 40,211,123,187,201, 67,193, 21,227,173,244,119,199,128,158 };

void QAND(int a, int b, int& c, int d)
{
	// two ancilla qubits with value zero
	if ((c != 0) || (d != 0))
	{
		cout << "Error!" << endl;
		exit(0);
	}
	c = a & b;
}

//conjugate of QAND, to reset the qubit 'c' calculated by 'QAND(a, b, c, 0)', where c = a&b;
//one QAND_C gate = 5 one-bit Clifford gates + 2 CNOT gates + 1 Measure, without T gates
//QAND_C(a, b, c) -> (a, b, 0);
void QAND_C(int a, int b, int& c)
{
	//we just simulate the QAND_C gate as the function to reset c for short;
	c = c ^ a & b;
}

int y_8 = 0, y_9 = 0, y_10 = 0, y_11 = 0, y_12 = 0, y_13 = 0, y_14 = 0, y_15 = 0, y_16 = 0, y_17 = 0;

int t_4 = 0, t_5 = 0, t_6 = 0, t_7 = 0, t_8 = 0, t_9 = 0, t_10 = 0, t_11 = 0, t_12 = 0;

int q_4 = 0, q_9 = 0, q_12 = 0;

int v_0 = 0, v_1 = 0, v_2 = 0, v_3 = 0, v_4 = 0, v_5 = 0, v_6 = 0;

int t_43 = 0, t_44 = 0, t_45 = 0, t_46 = 0, t_47 = 0;

int t_8_2 = 0, t_5_2 = 0, t_7_2 = 0, t_4_2 = 0;

int t_43_2 = 0, t_44_2 = 0, t_45_2 = 0, t_46_2 = 0, t_47_2 = 0;

int anc[15] = { 0 };

int z[18] = { 0 };

void f_1(int* x)
{
	x[2] = x[2] ^ x[4];
	x[4] = x[4] ^ x[1];
	x[1] = x[1] ^ x[6];
	x[7] = x[7] ^ x[0];
	x[5] = x[5] ^ x[1];
	x[1] = x[1] ^ x[2];
	y_9 = y_9 ^ x[7];
	y_13 = y_13 ^ x[2];
	y_10 = y_10 ^ x[1];
	y_14 = y_14 ^ x[1];
	y_14 = y_14 ^ x[5];
	x[1] = x[1] ^ x[0];
	y_17 = y_17 ^ x[7];
	y_11 = y_11 ^ x[4];
	y_12 = y_12 ^ x[5];
	y_17 = y_17 ^ x[4];
	x[4] = x[4] ^ x[2];
	x[2] = x[2] ^ x[7];
	x[0] = x[0] ^ x[5];
	x[3] = x[3] ^ x[2];
	x[5] = x[5] ^ x[3];
	x[6] = x[6] ^ x[3];
	x[7] = x[7] ^ x[6];
	y_15 = y_15 ^ x[6];
	y_16 = y_16 ^ x[3];
	y_13 = y_13 ^ x[6];
	y_16 = y_16 ^ x[0];
	y_15 = y_15 ^ x[4];
	y_8 = y_8 ^ x[5];
	y_8 = y_8 ^ x[1];
	x[1] = x[1] ^ 1;
	x[3] = x[3] ^ 1;
	x[2] = x[2] ^ 1;
	x[4] = x[4] ^ 1;
	y_8 = y_8 ^ 1;
	y_12 = y_12 ^ 1;
	y_13 = y_13 ^ 1;
	y_14 = y_14 ^ 1;
	y_15 = y_15 ^ 1;
	y_16 = y_16 ^ 1;

	QAND(x[4], x[0], t_4, anc[0]);
	QAND(y_17, y_16, t_5, anc[1]);
	QAND(x[2], x[3], t_6, anc[2]);
	QAND(y_13, y_12, t_7, anc[3]);
	QAND(y_11, y_10, t_8, anc[4]);
	QAND(y_15, y_14, t_9, anc[5]);
	QAND(x[6], x[1], t_10, anc[6]);
	QAND(y_9, y_8, t_11, anc[7]);
	QAND(x[7], x[5], t_12, anc[8]);

	t_8 = t_8 ^ t_7;
	t_7 = t_7 ^ t_9;
	t_4 = t_4 ^ t_5;
	t_5 = t_5 ^ t_7;
	t_4 = t_4 ^ t_8;
	t_8 = t_8 ^ t_10;
	t_7 = t_7 ^ t_12;
	t_5 = t_5 ^ t_6;
	t_8 = t_8 ^ t_11;
	t_7 = t_7 ^ t_11;


x[0] = x[0] ^ x[4];
y_8 = y_8 ^ y_9 ^ x[0];
x[2] = x[2] ^ x[3];
x[1] = x[1] ^ x[2] ^ x[6];

	t_4 = t_4 ^ x[1];
	t_5 = t_5 ^ y_8;
	t_8 = t_8 ^ x[2];
	t_7 = t_7 ^ x[0];

x[1] = x[1] ^ x[2] ^ x[6];
x[2] = x[2] ^ x[3];
y_8 = y_8 ^ y_9 ^ x[0];
x[0] = x[0] ^ x[4];

	//t_20 =  t_4;
	//t_22 =  t_5;
	//t_24 =  t_8;
	//t_26 =  t_7;
}

void S_4()
{
	//t_20 =  t_4;
	//t_22 =  t_5;
	//t_24 =  t_8;
	//t_26 =  t_7;

	t_7 = t_7 ^ t_5;
	q_4 = q_4 ^ t_7;   
	q_9 = q_9 ^ t_4;
	q_9 = q_9 ^ t_7;  
	t_4 = t_4 ^ t_8;  
	t_8 = t_8 ^ t_7;  
	t_5 = t_5 ^ t_4;  
	t_7 = t_7 ^ t_5; 
	t_7 = t_7 ^ 1;
	q_4 = q_4 ^ 1;

	QAND(t_8, t_7, v_0, anc[0]);
	QAND(q_4, t_5, v_2, anc[1]);
	QAND(t_4, q_9, v_4, anc[2]);

	q_4 = q_4 ^ 1;
	t_7 = t_7 ^ 1;
	t_7 = t_7 ^ t_5;  
	t_5 = t_5 ^ t_4;   
	t_8 = t_8 ^ t_7;   
	t_4 = t_4 ^ t_8;   
	q_9 = q_9 ^ t_7;  
	q_9 = q_9 ^ t_4;
	q_4 = q_4 ^ t_7; 
	t_7 = t_7 ^ t_5;

	v_2 = v_2 ^ t_7;
	q_12 = q_12 ^ t_4;  
	t_8 = t_8 ^ t_7;
	t_7 = t_7 ^ v_0;
	v_0 = v_0 ^ v_2;  
	t_7 = t_7 ^ t_4;  
	t_4 = t_4 ^ v_2;  
	v_2 = v_2 ^ t_5;
	v_4 = v_4 ^ t_8;   
	t_8 = t_8 ^ t_7;  
	v_2 = v_2 ^ t_8;  
	t_7 = t_7 ^ 1;
	v_2 = v_2 ^ 1;

	QAND(t_7, t_8, v_1, anc[0]);
	QAND(v_2, v_0, v_3, anc[1]);
	QAND(t_4, t_5, v_5, anc[2]);
	QAND(q_12, v_4, v_6, anc[3]);

	v_2 = v_2 ^ 1;
	t_7 = t_7 ^ 1;
	v_2 = v_2 ^ t_8; 
	t_8 = t_8 ^ t_7;  
	v_4 = v_4 ^ t_8;   
	v_2 = v_2 ^ t_5;
	t_4 = t_4 ^ v_2;  
	t_7 = t_7 ^ t_4;   
	v_0 = v_0 ^ v_2;  
	t_7 = t_7 ^ v_0;
	t_8 = t_8 ^ t_7;
	q_12 = q_12 ^ t_4;  
	v_2 = v_2 ^ t_7;

	t_8 = t_8 ^ t_4 ^ t_5 ^ v_0 ^ v_1 ^ v_2 ^ v_3 ^ v_5 ^ v_6;
	t_5 = t_5 ^ t_7 ^ v_1 ^ v_3 ^ v_4 ^ v_5;
	t_7 = t_7 ^ v_0 ^ v_3 ^ v_6;
	t_4 = t_4 ^ v_2 ^ v_3 ^ v_4 ^ v_5 ^ v_6;

	//cout << q_4 + q_9 + q_12;
	// t_31 = t_8;
	// t_35 = t_5;
	// t_39 = t_7;
	// t_42 = t_4;
}


void f_2(int* x, int* s)
{
	for (int i = 0; i < 8; i++)
	{
		s[i] = 0;
	}

	t_43 = t_43 ^ t_7;
	t_43 = t_43 ^ t_5;

	t_44 = t_44 ^ t_7;
	t_44 = t_44 ^ t_4;

	t_45 = t_45 ^ t_5;
	t_45 = t_45 ^ t_8;

	t_46 = t_46 ^ t_44;
	t_46 = t_46 ^ t_45;

	t_47 = t_47 ^ t_4;
	t_47 = t_47 ^ t_8;

	/*
	14 ancilla qubits:
	(8, 5, 7, 4): already allocated; 
	(43, 44, 45, 46, 47): new
	t_31,t_47,t_42,t_44,t_45,t_46,t_35,t_43,t_39,
	t_31,t_47,t_42,t_44,t_45,t_46,t_35,t_43,t_39: new
	*/

	t_8_2 = t_8_2 ^ t_8;
	t_47_2 = t_47_2 ^ t_47;
	t_4_2 = t_4_2 ^ t_4;
	t_44_2 = t_44_2 ^ t_44;
	t_45_2 = t_45_2 ^ t_45;
	t_46_2 = t_46_2 ^ t_46;
	t_5_2 = t_5_2 ^ t_5;
	t_43_2 = t_43_2 ^ t_43;
	t_7_2 = t_7_2 ^ t_7;

	QAND(t_8, x[7], z[0], anc[0]);
	QAND(t_47, y_9, z[1], anc[1]);
	QAND(t_4, x[6], z[2], anc[2]);
	QAND(t_44, y_15, z[3], anc[3]);
	QAND(t_45, y_13, z[4], anc[4]);
	QAND(t_46, y_11, z[5], anc[5]);
	QAND(t_5, x[2], z[6], anc[6]);
	QAND(t_43, y_17, z[7], anc[7]);
	QAND(t_7, x[4], z[8], anc[8]);
	QAND(t_8_2, x[5], z[9], anc[9]);
	QAND(t_47_2, y_8, z[10], anc[10]);
	QAND(t_4_2, x[1], z[11], anc[11]);
	QAND(t_44_2, y_14, z[12], anc[12]);
	QAND(t_45_2, y_12, z[13], anc[13]);
	QAND(t_46_2, y_10, z[14], anc[14]);
	QAND(t_5_2, x[3], z[15], q_4);
	QAND(t_43_2, y_16, z[16], q_9);
	QAND(t_7_2, x[0], z[17], q_12);

	z[0] = z[0] ^ z[2];
	z[3] = z[3] ^ z[5];
	z[10] = z[10] ^ z[9];
	z[12] = z[12] ^ z[13];
	z[13] = z[13] ^ z[16];
	z[4] = z[4] ^ z[5];
	z[13] = z[13] ^ z[17];
	z[1] = z[1] ^ z[2];
	z[4] = z[4] ^ z[1];
	z[1] = z[1] ^ z[7];
	z[12] = z[12] ^ z[10];
	z[9] = z[9] ^ z[11];
	z[9] = z[9] ^ z[17];
	z[1] = z[1] ^ z[3];
	z[10] = z[10] ^ z[15];
	z[3] = z[3] ^ z[0];
	z[0] = z[0] ^ z[6];
	z[0] = z[0] ^ z[8];
	z[9] = z[9] ^ z[15];
	z[10] = z[10] ^ z[16];
	z[1] = z[1] ^ z[6];
	z[12] = z[12] ^ z[1];
	z[4] = z[4] ^ z[12];
	z[13] = z[13] ^ z[14];
	z[10] = z[10] ^ z[3];
	z[4] = z[4] ^ z[10];
	z[13] = z[13] ^ z[0];
	z[9] = z[9] ^ z[1];

	s[0] = s[0] ^ z[9];
	s[1] = s[1] ^ z[1];
	s[2] = s[2] ^ z[4];
	s[3] = s[3] ^ z[12];
	s[4] = s[4] ^ z[3];
	s[5] = s[5] ^ z[13];
	s[6] = s[6] ^ z[0];
	s[7] = s[7] ^ z[10];

	s[1] = s[1] ^ 1;
	s[2] = s[2] ^ 1;
	s[4] = s[4] ^ 1;
	s[5] = s[5] ^ 1;
	s[6] = s[6] ^ 1;


	/////////////////////////////////reset/////////////////////////////////
	//to reset z_0 - z_17.
	z[9] = z[9] ^ z[1];
	z[13] = z[13] ^ z[0];
	z[4] = z[4] ^ z[10];
	z[10] = z[10] ^ z[3];
	z[13] = z[13] ^ z[14];
	z[4] = z[4] ^ z[12];
	z[12] = z[12] ^ z[1];
	z[1] = z[1] ^ z[6];
	z[10] = z[10] ^ z[16];
	z[9] = z[9] ^ z[15];
	z[0] = z[0] ^ z[8];
	z[0] = z[0] ^ z[6];
	z[3] = z[3] ^ z[0];
	z[10] = z[10] ^ z[15];
	z[1] = z[1] ^ z[3];
	z[9] = z[9] ^ z[17];
	z[9] = z[9] ^ z[11];
	z[12] = z[12] ^ z[10];
	z[1] = z[1] ^ z[7];
	z[4] = z[4] ^ z[1];
	z[1] = z[1] ^ z[2];
	z[13] = z[13] ^ z[17];
	z[4] = z[4] ^ z[5];
	z[13] = z[13] ^ z[16];
	z[12] = z[12] ^ z[13];
	z[10] = z[10] ^ z[9];
	z[3] = z[3] ^ z[5];
	z[0] = z[0] ^ z[2];

	//reset z_0 ~ z_17
	QAND_C(t_8, x[7], z[0]);
	QAND_C(t_47, y_9, z[1]);
	QAND_C(t_4, x[6], z[2]);
	QAND_C(t_44, y_15, z[3]);
	QAND_C(t_45, y_13, z[4]);
	QAND_C(t_46, y_11, z[5]);
	QAND_C(t_5, x[2], z[6]);
	QAND_C(t_43, y_17, z[7]);
	QAND_C(t_7, x[4], z[8]);
	QAND_C(t_8_2, x[5], z[9]);
	QAND_C(t_47_2, y_8, z[10]);
	QAND_C(t_4_2, x[1], z[11]);
	QAND_C(t_44_2, y_14, z[12]);
	QAND_C(t_45_2, y_12, z[13]);
	QAND_C(t_46_2, y_10, z[14]);
	QAND_C(t_5_2, x[3], z[15]);
	QAND_C(t_43_2, y_16, z[16]);
	QAND_C(t_7_2, x[0], z[17]);

	t_7_2 = t_7_2 ^ t_7;	
	t_43_2 = t_43_2 ^ t_43;
	t_5_2 = t_5_2 ^ t_5;
	t_46_2 = t_46_2 ^ t_46;
	t_45_2 = t_45_2 ^ t_45;
	t_44_2 = t_44_2 ^ t_44;
	t_4_2 = t_4_2 ^ t_4;
	t_47_2 = t_47_2 ^ t_47;
	t_8_2 = t_8_2 ^ t_8;

		t_47 = t_47 ^ t_8;
		t_47 = t_47 ^ t_4;

		t_46 = t_46 ^ t_45;
		t_46 = t_46 ^ t_44;

		t_45 = t_45 ^ t_8;
		t_45 = t_45 ^ t_5;

		t_44 = t_44 ^ t_4;
		t_44 = t_44 ^ t_7;

		t_43 = t_43 ^ t_5;
		t_43 = t_43 ^ t_7;


		//reset f_2
	t_4 = t_4 ^ v_2 ^ v_3 ^ v_4 ^ v_5 ^ v_6;	
	t_7 = t_7 ^ v_0 ^ v_3 ^ v_6;
	t_5 = t_5 ^ t_7 ^ v_1 ^ v_3 ^ v_4 ^ v_5;
	t_8 = t_8 ^ t_4 ^ t_5 ^ v_0 ^ v_1 ^ v_2 ^ v_3 ^ v_5 ^ v_6;

	v_2 = v_2 ^ t_7;
	q_12 = q_12 ^ t_4;  
	t_8 = t_8 ^ t_7;
	t_7 = t_7 ^ v_0;
	v_0 = v_0 ^ v_2;  
	t_7 = t_7 ^ t_4;   
	t_4 = t_4 ^ v_2; 
	v_2 = v_2 ^ t_5;
	v_4 = v_4 ^ t_8;  
	t_8 = t_8 ^ t_7;  
	v_2 = v_2 ^ t_8;  
	t_7 = t_7 ^ 1;
	v_2 = v_2 ^ 1;


	QAND_C(q_12, v_4, v_6);
	QAND_C(t_4, t_5, v_5);
	QAND_C(v_2, v_0, v_3);
	QAND_C(t_7, t_8, v_1);

	v_2 = v_2 ^ 1;
	t_7 = t_7 ^ 1;
	v_2 = v_2 ^ t_8;  
	t_8 = t_8 ^ t_7;   
	v_4 = v_4 ^ t_8;  
	v_2 = v_2 ^ t_5;
	t_4 = t_4 ^ v_2;  
	t_7 = t_7 ^ t_4;  
	v_0 = v_0 ^ v_2;  
	t_7 = t_7 ^ v_0;
	t_8 = t_8 ^ t_7;
	q_12 = q_12 ^ t_4;  
	v_2 = v_2 ^ t_7;

	t_7 = t_7 ^ t_5;
	q_4 = q_4 ^ t_7;   
	q_9 = q_9 ^ t_4;
	q_9 = q_9 ^ t_7;  
	t_4 = t_4 ^ t_8;   
	t_8 = t_8 ^ t_7;   
	t_5 = t_5 ^ t_4;   
	t_7 = t_7 ^ t_5;  
	t_7 = t_7 ^ 1;
	q_4 = q_4 ^ 1;

	QAND_C(t_4, q_9, v_4);
	QAND_C(q_4, t_5, v_2);
	QAND_C(t_8, t_7, v_0);

	q_4 = q_4 ^ 1;
	t_7 = t_7 ^ 1;
	t_7 = t_7 ^ t_5; 
	t_5 = t_5 ^ t_4;   
	t_8 = t_8 ^ t_7;   
	t_4 = t_4 ^ t_8;   
	q_9 = q_9 ^ t_7; 
	q_9 = q_9 ^ t_4;
	q_4 = q_4 ^ t_7;  
	t_7 = t_7 ^ t_5;

x[0] = x[0] ^ x[4];
y_8 = y_8 ^ y_9 ^ x[0];
x[2] = x[2] ^ x[3];
x[1] = x[1] ^ x[2] ^ x[6];

	t_4 = t_4 ^ x[1];
	t_5 = t_5 ^ y_8;
	t_8 = t_8 ^ x[2];
	t_7 = t_7 ^ x[0];

x[1] = x[1] ^ x[2] ^ x[6];
x[2] = x[2] ^ x[3];
y_8 = y_8 ^ y_9 ^ x[0];
x[0] = x[0] ^ x[4];
	
	t_7 = t_7 ^ t_11;
	t_8 = t_8 ^ t_11;
	t_5 = t_5 ^ t_6;
	t_7 = t_7 ^ t_12;
	t_8 = t_8 ^ t_10;
	t_4 = t_4 ^ t_8;
	t_5 = t_5 ^ t_7;
	t_4 = t_4 ^ t_5;
	t_7 = t_7 ^ t_9;
	t_8 = t_8 ^ t_7;

	QAND_C(x[7], x[5], t_12);
	QAND_C(y_9, y_8, t_11);
	QAND_C(x[6], x[1], t_10);
	QAND_C(y_15, y_14, t_9);
	QAND_C(y_11, y_10, t_8);
	QAND_C(y_13, y_12, t_7);
	QAND_C(x[2], x[3], t_6);
	QAND_C(y_17, y_16, t_5);
	QAND_C(x[4], x[0], t_4);

	y_16 = y_16 ^ 1;
	y_15 = y_15 ^ 1;
	y_14 = y_14 ^ 1;
	y_13 = y_13 ^ 1;
	y_12 = y_12 ^ 1;
	y_8 = y_8 ^ 1;
	x[4] = x[4] ^ 1;
	x[2] = x[2] ^ 1;
	x[3] = x[3] ^ 1;
	x[1] = x[1] ^ 1;

	y_8 = y_8 ^ x[1];
	y_8 = y_8 ^ x[5];
	y_15 = y_15 ^ x[4];
	y_16 = y_16 ^ x[0];
	y_13 = y_13 ^ x[6];
	y_16 = y_16 ^ x[3];
	y_15 = y_15 ^ x[6];
	x[7] = x[7] ^ x[6];
	x[6] = x[6] ^ x[3];
	x[5] = x[5] ^ x[3];
	x[3] = x[3] ^ x[2];
	x[0] = x[0] ^ x[5];
	x[2] = x[2] ^ x[7];
	x[4] = x[4] ^ x[2];
	y_17 = y_17 ^ x[4];
	y_12 = y_12 ^ x[5];
	y_11 = y_11 ^ x[4];
	y_17 = y_17 ^ x[7];
	x[1] = x[1] ^ x[0];
	y_14 = y_14 ^ x[5];
	y_14 = y_14 ^ x[1];
	y_10 = y_10 ^ x[1];
	y_13 = y_13 ^ x[2];
	y_9 = y_9 ^ x[7];
	x[1] = x[1] ^ x[2];
	x[5] = x[5] ^ x[1];
	x[7] = x[7] ^ x[0];
	x[1] = x[1] ^ x[6];
	x[4] = x[4] ^ x[1];
	x[2] = x[2] ^ x[4];
	 	
	cout << y_8<< y_9<< y_10<< y_11<< y_12<< y_13<< y_14<< y_15<< y_16<< y_17 ;

	cout << t_4<< t_5<< t_6<< t_7<< t_8<< t_9<< t_10<< t_11<< t_12 ;

	cout << q_4<< q_9<< q_12 ;

	cout << v_0<< v_1<< v_2<< v_3<< v_4<< v_5<< v_6 ;

	cout << t_43<< t_44<< t_45<< t_46<< t_47 ;

	cout << t_8_2<< t_5_2<< t_7_2 << t_4_2 ;

	cout << t_43_2<< t_44_2<< t_45_2<< t_46_2<< t_47_2;
	for (int i = 0; i < 18; i++)
	{
		cout<<z[i];
	}
	//00000000000000000000000000000000000000000000000000000000000000: 62 0s, where the last 0 is to judge if the S-box output is right. 
	//That is, the first 61 0s are used to mark the last values of the 61 ancilla qubits. Note that there there has anc[15], totally, 61+15 = 76 ancilla qubits.  
}

void camellia_forward_sbox(int* x, int* s)
{
	f_1(x);
	S_4();
	f_2(x, s);
}

void initial_ancilla()
{
	y_8 = 0; y_9 = 0; y_10 = 0; y_11 = 0; y_12 = 0; y_13 = 0; y_14 = 0; y_15 = 0; y_16 = 0; y_17 = 0;

	t_4 = 0; t_5 = 0; t_6 = 0; t_7 = 0; t_8 = 0; t_9 = 0; t_10 = 0; t_11 = 0; t_12 = 0;

	q_4 = 0; q_9 = 0; q_12 = 0;

	v_0 = 0; v_1 = 0; v_2 = 0; v_3 = 0; v_4 = 0; v_5 = 0; v_6 = 0;

	t_43 = 0; t_44 = 0; t_45 = 0; t_46 = 0; t_47 = 0;

	t_8_2 = 0; t_5_2 = 0; t_7_2 = 0; t_4_2 = 0;

	t_43_2 = 0; t_44_2 = 0; t_45_2 = 0; t_46_2 = 0; t_47_2 = 0;


	for (int i = 0; i < 18; i++)
	{
		z[i] = 0;
		anc[i] = 0;
	}
}

int main()
{
	for (int i = 0; i < 256; i++)
	{  //i = 76543210
		int in[8] = { 0 };
		int out[8] = { 0 };

		in[0] = (i & 1);
		in[1] = (i >> 1 & 1);
		in[2] = (i >> 2 & 1);
		in[3] = (i >> 3 & 1);
		in[4] = (i >> 4 & 1);
		in[5] = (i >> 5 & 1);
		in[6] = (i >> 6 & 1);
		in[7] = (i >> 7 & 1);

		initial_ancilla();

		camellia_forward_sbox(in, out);

		int sum = out[0] * 128 + out[1] * 64 + out[2] * 32 + out[3] * 16 + out[4] * 8 + out[5] * 4 + out[6] * 2 + out[7];
		if ((i != 0) && ((i % 16 == 0)))
		{
			cout << endl;
		}
		if (sum == sbox[i])
		{
			cout << "0  ";
		}
		else if (sum != sbox[i])
		{
			cout << "1  ";
		}
	}
	cout << endl;
	return 0;
}