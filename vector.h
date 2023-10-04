#pragma once
#include <Novice.h>
#include <assert.h>
#include<cmath>
#include <stdio.h>

int kWindowWidth = 1280;
int kWindowHeight = 720;

typedef struct Matrix2x2 {
	float m[2][2];
} Matrix2x2;

typedef struct Matrix3x3 {
	float m[3][3];
} Matrix3x3;

typedef struct Matrix4x4 {
	float m[4][4];
} Matrix4x4;

typedef struct Vector2 {
	float x;
	float y;
} Vector2;

typedef struct Vector3 {
	float x;
	float y;
	float z;
} Vector3;


Matrix2x2 Add(Matrix2x2 a, Matrix2x2 b) {
	Matrix2x2 add;
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			add.m[x][y] = a.m[x][y] + b.m[x][y];
		}
	}
	return add;
}
Matrix2x2 Subtract(Matrix2x2 a, Matrix2x2 b) {
	Matrix2x2 subtract;
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			subtract.m[x][y] = a.m[x][y] - b.m[x][y];
		}
	}
	return subtract;
}
Matrix2x2 Multiply(Matrix2x2 a, Matrix2x2 b) {
	Matrix2x2 multiply;
	multiply.m[0][0] = (a.m[0][0] * b.m[0][0]) + (a.m[0][1] * b.m[1][0]);
	multiply.m[0][1] = (a.m[0][0] * b.m[0][1]) + (a.m[0][1] * b.m[1][1]);
	multiply.m[1][0] = (a.m[1][0] * b.m[0][0]) + (a.m[1][1] * b.m[1][0]);
	multiply.m[1][1] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);

	return multiply;
}

Vector2 Multiply(Vector2 v, Matrix2x2 b) {
	Vector2 multiply;
	multiply.x = (v.x * b.m[0][0]) + (v.y * b.m[1][0]);
	multiply.y = (v.x * b.m[0][1]) + (v.y * b.m[1][1]);
	return multiply;
}

Matrix3x3 Multiply(Matrix3x3 a, Matrix3x3 b) {
	Matrix3x3 multiply;
	multiply.m[0][0] = (a.m[0][0] * b.m[0][0]) + (a.m[0][1] * b.m[1][0]);
	multiply.m[0][1] = (a.m[0][0] * b.m[0][1]) + (a.m[0][1] * b.m[1][1]);
	multiply.m[0][2] = (a.m[0][0] * b.m[0][1]) + (a.m[0][1] * b.m[1][1]);
	multiply.m[1][0] = (a.m[1][0] * b.m[0][0]) + (a.m[1][1] * b.m[1][0]);
	multiply.m[1][1] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);
	multiply.m[1][2] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);
	multiply.m[2][0] = (a.m[1][0] * b.m[0][0]) + (a.m[1][1] * b.m[1][0]);
	multiply.m[2][1] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);
	multiply.m[2][2] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);

	return multiply;
}

static const int kRowHeight = 20;
static const int kcolumnWidth = 54;
void MatrixScreenPrintf(int x, int y, Matrix2x2 z) {
	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < 2; column++) {
			Novice::ScreenPrintf(
				x + column * kcolumnWidth, y + row * kRowHeight, "%.02f", z.m[row][column]);
		}
	}
}

void VectorScreenPrintf(int x, int y, Vector2 z) {
	Novice::ScreenPrintf(x, y, "%.02f", z.x);
	Novice::ScreenPrintf(x + kcolumnWidth, y, "%.02f", z.y);
}

//float theta = (1.0 / 16.0f) * M_PI;

int kWorld = 500;

static const int kColumnWidth = 60;
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%s", label);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%.02f", vector.z);
}

void MatrixScreenPrintf(int x, int y, Matrix4x4& z) {
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			Novice::ScreenPrintf(
				x + column * kcolumnWidth, y + row * kRowHeight, "%6.02f", z.m[row][column]);
		}
	}
}


Matrix2x2 MakeRotateMatrix(float theta) {

	Matrix2x2 rotate;
	rotate.m[0][0] = std::cos(theta);
	rotate.m[0][1] = std::sin(theta);
	rotate.m[1][0] = -std::sin(theta);
	rotate.m[1][1] = std::cos(theta);

	return rotate;
};

Matrix3x3 makeRotateMatrix(float theta) {

	Matrix3x3 rotate;
	rotate.m[0][0] = std::cos(theta);
	rotate.m[1][0] = -std::sin(theta);
	rotate.m[2][0] = 0;
	rotate.m[0][1] = std::sin(theta);
	rotate.m[1][1] = std::cos(theta);
	rotate.m[2][1] = 0;
	rotate.m[0][2] = 0;
	rotate.m[1][2] = 0;
	rotate.m[2][2] = 1;

	return rotate;
};

Matrix3x3 MakeTranslateMatrix(Vector2 translate)
{
	Matrix3x3 result;
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[2][0] = translate.x;
	result.m[2][1] = translate.y;
	result.m[2][2] = 1.0f;

	return result;
}

Vector2 Transform(Vector2 vector, Matrix3x3 matrix) {
	Vector2 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	return result;
}


Matrix2x2 Inverse(Matrix2x2 a) {
	Matrix2x2 result = {0};
	float x = a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0];
	if (x != 0) {
		result.m[0][0] = 1 / x * a.m[1][1];
		result.m[0][1] = 1 / x * -(a.m[0][1]);
		result.m[1][0] = 1 / x * -(a.m[1][0]);
		result.m[1][1] = 1 / x * a.m[0][0];
	}
	return result;
}

Matrix3x3 Inverse(Matrix3x3 a) {
	Matrix3x3 result;
	float x = a.m[0][0] * a.m[1][1] * a.m[2][2] + a.m[0][1] * a.m[1][2] * a.m[2][1] +
		a.m[0][2] * a.m[1][0] * a.m[2][1] - a.m[2][0] * a.m[1][1] * a.m[2][0] -
		a.m[0][1] * a.m[2][1] * a.m[2][2] - a.m[0][0] * a.m[1][0] * a.m[2][1];
	if (x != 0) {
		result.m[0][0] = 1 / x * (a.m[1][1] * a.m[2][2] - a.m[1][2] * a.m[2][1]);
		result.m[0][1] = 1 / x * -(a.m[0][1] * a.m[2][2] - a.m[0][2] * a.m[2][1]);
		result.m[0][2] = 1 / x * (a.m[0][1] * a.m[1][2] - a.m[0][2] * a.m[1][1]);
		result.m[1][0] = 1 / x * -(a.m[1][0] * a.m[2][2] - a.m[1][2] * a.m[2][0]);
		result.m[1][1] = 1 / x * (a.m[0][0] * a.m[2][2] - a.m[0][2] * a.m[2][0]);
		result.m[1][2] = 1 / x * -(a.m[0][0] * a.m[1][2] - a.m[0][2] * a.m[1][0]);
		result.m[2][0] = 1 / x * (a.m[1][0] * a.m[2][1] - a.m[1][1] * a.m[2][0]);
		result.m[2][1] = 1 / x * -(a.m[0][0] * a.m[2][1] - a.m[0][1] * a.m[2][0]);
		result.m[2][2] = 1 / x * (a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0]);
	}
	return result;
}

Matrix2x2 TransposeM1(Matrix2x2 a) {
	Matrix2x2 result;
	result.m[0][0] = a.m[0][0];
	result.m[1][1] = a.m[1][1];
	result.m[0][1] = a.m[1][0];
	result.m[1][0] = a.m[0][1];
	return result;
}

Matrix3x3 TransposeM2(Matrix3x3 a) {
	Matrix3x3 result;
	result.m[0][0] = a.m[0][0];
	result.m[1][0] = a.m[0][1];
	result.m[2][0] = a.m[0][2];
	result.m[0][1] = a.m[1][0];
	result.m[1][1] = a.m[1][1];
	result.m[2][1] = a.m[1][2];
	result.m[0][2] = a.m[2][0];
	result.m[1][2] = a.m[2][1];
	result.m[2][2] = a.m[2][2];
	return result;
}


Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom) {//正射影
	Matrix3x3 result;
	result.m[0][0] = 2.0f / (right - left);
	result.m[1][0] = 0;
	result.m[2][0] = (left + right) / (left - right);
	result.m[0][1] = 0;
	result.m[1][1] = 2.0f / (top - bottom);
	result.m[2][1] = (top + bottom) / (bottom - top);
	result.m[0][2] = 0;
	result.m[1][2] = 0;
	result.m[2][2] = 1;
	return result;
}
Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height) { //ビューポート
	Matrix3x3 result;
	result.m[0][0] = width / 2;
	result.m[1][0] = 0;
	result.m[2][0] = left + width / 2;
	result.m[0][1] = 0;
	result.m[1][1] = -height / 2;
	result.m[2][1] = top + height / 2;
	result.m[0][2] = 0;
	result.m[1][2] = 0;
	result.m[2][2] = 1;
	return result;
}
Matrix3x3 Inverse3x3(Matrix3x3 a) {
	Matrix3x3 result;
	result.m[2][0] = -a.m[2][0];
	result.m[2][1] = -a.m[2][1];
	return result;
};

Vector2 Lerp(const Vector2& a, const Vector2& b, float t) {
	Vector2 f;
	f.x = t * a.x + (1.0f - t) * b.x;
	f.y = t * a.y + (1.0f - t) * b.y;
	return f;

}

Vector2 Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, float t) {
	Vector2 p0p1 = Lerp(p0, p1, t);
	Vector2 p1p2 = Lerp(p1, p2, t);
	Vector2 p = Lerp(p0p1, p1p2, t);
	return p;
}


Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 v3 = {
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
	};
	return v3;
};
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 v3 = {
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	};
	return v3;
};

Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 v3 = {
	v.x * scalar,
	v.y * scalar,
	v.z * scalar
	};
	return v3;
}

float Dot(const Vector3& v1, const Vector3& v2) {
	float dot;
	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return dot;
}

float Length(const Vector3& v) {
	float length;
	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return length;
}

Vector3 Normalize(const Vector3& v) {
	float length;
	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	Vector3 normalize{
		v.x / length,
		v.y / length,
		v.z / length,
	};
	return normalize;
}

Matrix4x4 Add(Matrix4x4 a, Matrix4x4 b) {
	Matrix4x4 add;
	add.m[0][0] = a.m[0][0] + b.m[0][0];
	add.m[0][1] = a.m[0][1] + b.m[0][1];
	add.m[0][2] = a.m[0][2] + b.m[0][2];
	add.m[0][3] = a.m[0][3] + b.m[0][3];
	add.m[1][0] = a.m[1][0] + b.m[1][0];
	add.m[1][1] = a.m[1][1] + b.m[1][1];
	add.m[1][2] = a.m[1][2] + b.m[1][2];
	add.m[1][3] = a.m[1][3] + b.m[1][3];
	add.m[2][0] = a.m[2][0] + b.m[2][0];
	add.m[2][1] = a.m[2][1] + b.m[2][1];
	add.m[2][2] = a.m[2][2] + b.m[2][2];
	add.m[2][3] = a.m[2][3] + b.m[2][3];
	add.m[3][0] = a.m[3][0] + b.m[3][0];
	add.m[3][1] = a.m[3][1] + b.m[3][1];
	add.m[3][2] = a.m[3][2] + b.m[3][2];
	add.m[3][3] = a.m[3][3] + b.m[3][3];
	return add;
}

Matrix4x4 Subtract(Matrix4x4 a, Matrix4x4 b) {
	Matrix4x4 subtract;
	subtract.m[0][1] = a.m[0][1] - b.m[0][1];
	subtract.m[0][0] = a.m[0][0] - b.m[0][0];
	subtract.m[0][2] = a.m[0][2] - b.m[0][2];
	subtract.m[0][3] = a.m[0][3] - b.m[0][3];
	subtract.m[1][0] = a.m[1][0] - b.m[1][0];
	subtract.m[1][1] = a.m[1][1] - b.m[1][1];
	subtract.m[1][2] = a.m[1][2] - b.m[1][2];
	subtract.m[1][3] = a.m[1][3] - b.m[1][3];
	subtract.m[2][0] = a.m[2][0] - b.m[2][0];
	subtract.m[2][1] = a.m[2][1] - b.m[2][1];
	subtract.m[2][2] = a.m[2][2] - b.m[2][2];
	subtract.m[2][3] = a.m[2][3] - b.m[2][3];
	subtract.m[3][0] = a.m[3][0] - b.m[3][0];
	subtract.m[3][1] = a.m[3][1] - b.m[3][1];
	subtract.m[3][2] = a.m[3][2] - b.m[3][2];
	subtract.m[3][3] = a.m[3][3] - b.m[3][3];
	return subtract;
}

Matrix4x4 Multiply(Matrix4x4 a, Matrix4x4 b) {
	Matrix4x4 multiply;
	multiply.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0] +
	                   a.m[0][3] * b.m[3][0];
	multiply.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1] +
	                   a.m[0][3] * b.m[3][1];
	multiply.m[0][2] = a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2] +
	                   a.m[0][3] * b.m[3][2];
	multiply.m[0][3] = a.m[0][0] * b.m[0][3] + a.m[0][1] * b.m[1][3] + a.m[0][2] * b.m[2][3] +
	                   a.m[0][3] * b.m[3][3];
	multiply.m[1][0] = a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0] +
	                   a.m[1][3] * b.m[3][0];
	multiply.m[1][1] = a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] +
	                   a.m[1][3] * b.m[3][1];
	multiply.m[1][2] = a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] +
	                   a.m[1][3] * b.m[3][2];
	multiply.m[1][3] = a.m[1][0] * b.m[0][3] + a.m[1][1] * b.m[1][3] + a.m[1][2] * b.m[2][3] +
	                   a.m[1][3] * b.m[3][3];
	multiply.m[2][0] = a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0] +
	                   a.m[2][3] * b.m[3][0];
	multiply.m[2][1] = a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] +
	                   a.m[2][3] * b.m[3][1];
	multiply.m[2][2] = a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] +
	                   a.m[2][3] * b.m[3][2];
	multiply.m[2][3] = a.m[2][0] * b.m[0][3] + a.m[2][1] * b.m[1][3] + a.m[2][2] * b.m[2][3] +
	                   a.m[2][3] * b.m[3][3];
	multiply.m[3][0] = a.m[3][0] * b.m[0][0] + a.m[3][1] * b.m[1][0] + a.m[3][2] * b.m[2][0] +
	                   a.m[3][3] * b.m[3][0];
	multiply.m[3][1] = a.m[3][0] * b.m[0][1] + a.m[3][1] * b.m[1][1] + a.m[3][2] * b.m[2][1] +
	                   a.m[3][3] * b.m[3][1];
	multiply.m[3][2] = a.m[3][0] * b.m[0][2] + a.m[3][1] * b.m[1][2] + a.m[3][2] * b.m[2][2] +
	                   a.m[3][3] * b.m[3][2];
	multiply.m[3][3] = a.m[3][0] * b.m[0][3] + a.m[3][1] * b.m[1][3] + a.m[3][2] * b.m[2][3] +
	                   a.m[3][3] * b.m[3][3];

	return multiply;
}
//逆行列
Matrix4x4 Inverse(Matrix4x4 a) {
	Matrix4x4 result = a;
	float x = a.m[0][0] * a.m[1][1] * a.m[2][2] * a.m[3][3] +
		      a.m[0][0] * a.m[1][2] * a.m[2][3] * a.m[3][1] +
		      a.m[0][0] * a.m[1][3] * a.m[2][1] * a.m[3][2] -
		      a.m[0][0] * a.m[1][3] * a.m[2][2] * a.m[3][1] -
		      a.m[0][0] * a.m[1][2] * a.m[2][1] * a.m[3][3] -
		      a.m[0][0] * a.m[1][1] * a.m[2][3] * a.m[3][1] -
		      a.m[0][1] * a.m[1][0] * a.m[2][2] * a.m[3][3] -
		      a.m[0][2] * a.m[1][0] * a.m[2][3] * a.m[3][1] -
		      a.m[0][3] * a.m[1][0] * a.m[2][1] * a.m[3][2] +
		      a.m[0][3] * a.m[1][0] * a.m[2][2] * a.m[3][1] +
		      a.m[0][2] * a.m[1][0] * a.m[2][1] * a.m[3][3] +
		      a.m[0][1] * a.m[1][0] * a.m[2][3] * a.m[3][2] +
		      a.m[0][1] * a.m[1][2] * a.m[2][0] * a.m[3][3] +
		      a.m[0][2] * a.m[1][3] * a.m[2][0] * a.m[3][1] +
		      a.m[0][3] * a.m[1][1] * a.m[2][0] * a.m[3][2] -
		      a.m[0][3] * a.m[1][2] * a.m[2][0] * a.m[3][1] -
		      a.m[0][2] * a.m[1][1] * a.m[2][0] * a.m[3][3] -
		      a.m[0][1] * a.m[1][3] * a.m[2][0] * a.m[3][2] -
		      a.m[0][1] * a.m[1][2] * a.m[2][3] * a.m[3][0] -
		      a.m[0][2] * a.m[1][3] * a.m[2][1] * a.m[3][0] -
		      a.m[0][3] * a.m[1][1] * a.m[2][2] * a.m[3][0] +
		      a.m[0][3] * a.m[1][2] * a.m[2][1] * a.m[3][0] +
		      a.m[0][2] * a.m[1][1] * a.m[2][3] * a.m[3][0] +
		      a.m[0][1] * a.m[1][3] * a.m[2][2] * a.m[3][0];


	if (x != 0) {
		result.m[0][0] = 1 / x *
			(a.m[1][1] * a.m[2][2] * a.m[3][3] + a.m[1][2] * a.m[2][3] * a.m[3][1] + a.m[1][3] * a.m[2][1] * a.m[3][2]
				- a.m[1][3] * a.m[2][2] * a.m[3][1] - a.m[1][2] * a.m[2][1] * a.m[3][3] - a.m[1][1] * a.m[2][3] * a.m[3][2]);

		result.m[0][1] = 1 / x *
			(-a.m[0][1] * a.m[2][2] * a.m[3][3] - a.m[0][2] * a.m[2][3] * a.m[3][1] - a.m[0][3] * a.m[2][1] * a.m[3][2]
				+ a.m[0][3] * a.m[2][2] * a.m[3][1] + a.m[1][2] * a.m[2][1] * a.m[3][3] + a.m[0][1] * a.m[2][3] * a.m[3][2]);

		result.m[0][2] = 1 / x *
			(a.m[0][1] * a.m[1][2] * a.m[3][3] + a.m[0][2] * a.m[1][3] * a.m[3][1] + a.m[0][3] * a.m[1][1] * a.m[3][2]
				- a.m[0][3] * a.m[1][2] * a.m[3][1] - a.m[0][2] * a.m[1][1] * a.m[3][3] - a.m[0][1] * a.m[1][3] * a.m[3][2]);

		result.m[0][3] = 1 / x *
			(-a.m[0][1] * a.m[1][2] * a.m[2][3] - a.m[1][2] * a.m[1][3] * a.m[2][1] - a.m[0][3] * a.m[1][1] * a.m[2][2]
				+ a.m[0][3] * a.m[1][2] * a.m[2][1] - a.m[0][2] * a.m[1][1] * a.m[2][3] + a.m[0][1] * a.m[1][3] * a.m[2][2]);

		result.m[1][0] = 1 / x *
			(-a.m[1][0] * a.m[2][2] * a.m[3][3] - a.m[1][2] * a.m[2][3] * a.m[3][0] - a.m[1][3] * a.m[2][0] * a.m[3][2]
				+ a.m[1][3] * a.m[2][2] * a.m[3][0] + a.m[1][2] * a.m[2][0] * a.m[3][3] + a.m[1][0] * a.m[2][3] * a.m[3][2]);

		result.m[1][1] = 1 / x *
			(a.m[0][0] * a.m[2][2] * a.m[3][3] + a.m[0][2] * a.m[2][3] * a.m[3][0] + a.m[0][3] * a.m[2][0] * a.m[3][2]
				- a.m[0][3] * a.m[2][2] * a.m[3][0] - a.m[0][2] * a.m[2][0] * a.m[3][3] - a.m[0][0] * a.m[2][3] * a.m[3][2]);

		result.m[1][2] = 1 / x *
			(-a.m[0][0] * a.m[1][2] * a.m[3][3] - a.m[0][2] * a.m[1][3] * a.m[3][0] - a.m[0][3] * a.m[1][0] * a.m[3][2]
				+ a.m[0][3] * a.m[1][2] * a.m[3][0] + a.m[0][2] * a.m[1][0] * a.m[3][3] + a.m[0][0] * a.m[1][3] * a.m[3][2]);

		result.m[1][3] = 1 / x *
			(a.m[0][0] * a.m[1][2] * a.m[2][3] + a.m[0][2] * a.m[1][3] * a.m[2][0] + a.m[0][3] * a.m[1][0] * a.m[2][2]
				- a.m[0][3] * a.m[1][2] * a.m[2][0] - a.m[1][2] * a.m[1][0] * a.m[2][3] - a.m[0][0] * a.m[1][3] * a.m[2][2]);

		result.m[2][0] = 1 / x *
			(a.m[1][0] * a.m[2][1] * a.m[3][3] + a.m[1][1] * a.m[2][3] * a.m[3][0] + a.m[1][3] * a.m[2][0] * a.m[3][1]
				- a.m[1][3] * a.m[2][1] * a.m[3][0] - a.m[1][1] * a.m[2][0] * a.m[3][3] - a.m[1][0] * a.m[2][3] * a.m[3][1]);

		result.m[2][1] = 1 / x *
			(-a.m[0][0] * a.m[2][1] * a.m[3][3] - a.m[1][0] * a.m[2][3] * a.m[3][0] - a.m[0][3] * a.m[2][0] * a.m[3][1]
				+ a.m[0][3] * a.m[2][1] * a.m[3][0] + a.m[0][1] * a.m[2][0] * a.m[3][3] + a.m[0][0] * a.m[2][3] * a.m[3][1]);

		result.m[2][2] = 1 / x *
			(a.m[0][0] * a.m[1][1] * a.m[3][3] + a.m[0][1] * a.m[1][3] * a.m[3][0] + a.m[0][3] * a.m[1][0] * a.m[3][1]
				- a.m[0][3] * a.m[1][1] * a.m[3][0] - a.m[0][1] * a.m[1][3] * a.m[2][0] - a.m[0][0] * a.m[1][3] * a.m[3][1]);

		result.m[2][3] = 1 / x *
			(-a.m[0][0] * a.m[1][1] * a.m[2][3] - a.m[0][1] * a.m[1][3] * a.m[2][0] - a.m[0][3] * a.m[1][0] * a.m[2][1]
				+ a.m[0][3] * a.m[1][1] * a.m[2][0] + a.m[0][1] * a.m[1][0] * a.m[2][3] + a.m[0][0] * a.m[1][3] * a.m[2][1]);

		result.m[3][0] = 1 / x *
			(-a.m[1][0] * a.m[2][1] * a.m[3][2] - a.m[1][1] * a.m[2][2] * a.m[3][0] - a.m[1][2] * a.m[2][0] * a.m[3][1]
				+ a.m[1][2] * a.m[2][1] * a.m[3][0] + a.m[1][1] * a.m[2][0] * a.m[3][2] + a.m[1][0] * a.m[2][2] * a.m[3][1]);

		result.m[3][1] = 1 / x *
			(a.m[0][0] * a.m[2][1] * a.m[3][2] + a.m[0][1] * a.m[2][2] * a.m[3][0] + a.m[0][2] * a.m[2][0] * a.m[3][1]
				- a.m[0][2] * a.m[2][1] * a.m[3][0] - a.m[0][1] * a.m[2][0] * a.m[3][2] - a.m[0][0] * a.m[2][2] * a.m[3][1]);

		result.m[3][2] = 1 / x *
			(-a.m[0][0] * a.m[1][1] * a.m[3][2] - a.m[0][1] * a.m[1][2] * a.m[3][0] - a.m[0][2] * a.m[1][0] * a.m[3][1]
				+ a.m[0][2] * a.m[1][1] * a.m[3][0] + a.m[0][1] * a.m[1][0] * a.m[3][2] + a.m[0][0] * a.m[1][2] * a.m[3][1]);

		result.m[3][3] = 1 / x *
			(a.m[0][0] * a.m[1][1] * a.m[2][2] + a.m[0][1] * a.m[1][2] * a.m[2][0] + a.m[0][2] * a.m[1][0] * a.m[2][1]
				- a.m[0][2] * a.m[1][1] * a.m[2][0] - a.m[0][1] * a.m[1][0] * a.m[2][2] - a.m[0][0] * a.m[1][2] * a.m[2][1]);
	}
	return result;
}
//転置行列
Matrix4x4 Transpose(Matrix4x4 a) {
	Matrix4x4 result;
	result.m[0][0] = a.m[0][0];
	result.m[0][1] = a.m[1][0];
	result.m[0][2] = a.m[2][0];
	result.m[0][3] = a.m[3][0];
	result.m[1][0] = a.m[0][1];
	result.m[1][1] = a.m[1][1];
	result.m[1][2] = a.m[2][1];
	result.m[1][3] = a.m[3][1];
	result.m[2][0] = a.m[0][2];
	result.m[2][1] = a.m[1][2];
	result.m[2][2] = a.m[2][2];
	result.m[2][3] = a.m[3][2];
	result.m[3][0] = a.m[0][3];
	result.m[3][1] = a.m[1][3];
	result.m[3][2] = a.m[2][3];
	result.m[3][3] = a.m[3][3];
	return result;
}

Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 result;
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 result;
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1.0f;

	return result;
}

Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 result;
	result.m[0][0] = scale.x;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = scale.y;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = scale.z;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix)
{
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

Matrix4x4 MakerotateXMatrix(float radian) {
	Matrix4x4 rotate;
	rotate.m[0][0] = 1.0f;
	rotate.m[0][1] = 0.0f;
	rotate.m[0][2] = 0.0f;
	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = 0.0f;
	rotate.m[1][1] = std::cos(radian);
	rotate.m[1][2] = std::sin(radian);
	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = 0.0f;
	rotate.m[2][1] = -std::sin(radian);
	rotate.m[2][2] = std::cos(radian);
	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f;
	rotate.m[3][1] = 0.0f;
	rotate.m[3][2] = 0.0f;
	rotate.m[3][3] = 1.0f;

	return rotate;
}

Matrix4x4 MakerotateYMatrix(float radian) {
	Matrix4x4 rotate;
	rotate.m[0][0] = std::cos(radian);
	rotate.m[0][1] = 0.0f;
	rotate.m[0][2] = -std::sin(radian);
	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = 0.0f;
	rotate.m[1][1] = 1.0f;
	rotate.m[1][2] = 0.0f;
	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = std::sin(radian);
	rotate.m[2][1] = 0.0f;
	rotate.m[2][2] = std::cos(radian);
	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f;
	rotate.m[3][1] = 0.0f;
	rotate.m[3][2] = 0.0f;
	rotate.m[3][3] = 1.0f;

	return rotate;
}

Matrix4x4 MakerotateZMatrix(float radian) {
	Matrix4x4 rotate;
	rotate.m[0][0] = std::cos(radian);
	rotate.m[0][1] = std::sin(radian);
	rotate.m[0][2] = 0.0f;
	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = -std::sin(radian);
	rotate.m[1][1] = std::cos(radian);
	rotate.m[1][2] = 0.0f;
	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = 0.0f;
	rotate.m[2][1] = 0.0f;
	rotate.m[2][2] = 1.0f;
	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f;
	rotate.m[3][1] = 0.0f;
	rotate.m[3][2] = 0.0f;
	rotate.m[3][3] = 1.0f;

	return rotate;
}

Matrix4x4 MakeAffineMatrix(Vector3 scale, Vector3 rotate, Vector3 translate) {
	Matrix4x4 result;
	Matrix4x4 rotateX = MakerotateXMatrix(rotate.x);
	Matrix4x4 rotateY = MakerotateYMatrix(rotate.y);
	Matrix4x4 rotateZ = MakerotateZMatrix(rotate.z);
	Matrix4x4 ROTATE = Multiply(rotateX, Multiply(rotateY, rotateZ));
	result.m[0][0] = scale.x * ROTATE.m[0][0];
	result.m[0][1] = scale.x * ROTATE.m[0][1];
	result.m[0][2] = scale.x * ROTATE.m[0][2];
	result.m[0][3] = 0.0f;
	result.m[1][0] = scale.y * ROTATE.m[1][0];
	result.m[1][1] = scale.y * ROTATE.m[1][1];
	result.m[1][2] = scale.y * ROTATE.m[1][2];
	result.m[1][3] = 0.0f;
	result.m[2][0] = scale.z * ROTATE.m[2][0];
	result.m[2][1] = scale.z * ROTATE.m[2][1];
	result.m[2][2] = scale.z * ROTATE.m[2][2];
	result.m[2][3] = 0.0f;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1.0f;

	return result;

};
//透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 result;
	result.m[0][0] = 1 / aspectRatio * 1 / std::tan(fovY / 2);
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = 1 / std::tan(fovY / 2);
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = farClip / (farClip - nearClip);
	result.m[2][3] = 1;
	result.m[3][0] = 0;	
	result.m[3][1] = 0;
	result.m[3][2] = -nearClip * farClip / (farClip - nearClip);
	result.m[3][3] = 0;

	return result;
}
//正射影・viewProjection
Matrix4x4 MakeOrthographicMatrix(
    float left, float top, float right, float bottom, float nearClip /*基本0*/, float farClip) {
	Matrix4x4 result;
	result.m[0][0] = 2.0f / (right - left);
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = 2.0f / (top - bottom);
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1.0f / (farClip - nearClip);
	result.m[2][3] = 0;
	result.m[3][0] = (left + right) / (left - right);
	result.m[3][1] = (top + bottom) / (bottom - top);
	result.m[3][2] = nearClip / (nearClip - farClip);
	result.m[3][3] = 1.0f;

	return result;
}
//ビューポート
Matrix4x4 MakeViewportMatrix(
   float left, float top, float width, float height, 
   float minDepth /*基本0*/, float maxDepth /*基本1*/)
{
	Matrix4x4 result;
	result.m[0][0] = width / 2;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;
	result.m[1][0] = 0;
	result.m[1][1] = -height / 2;
	result.m[1][2] = 0;
	result.m[1][3] = 0;
	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = maxDepth - minDepth;
	result.m[2][3] = 0;
	result.m[3][0] = left + width / 2;
	result.m[3][1] = top + height / 2;
	result.m[3][2] = minDepth;
	result.m[3][3] = 1;

	return result;
}

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;

	return result;
}
Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m) {
	Vector3 result{
	    v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0],
	    v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1],
	    v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2],
	};
	return result;
}