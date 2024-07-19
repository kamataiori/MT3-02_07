#pragma once
#include "Mathfu_nctions.h"
#include "imgui.h"


class Result
{
public:

	//Sphere sphere
	//{
	//	0,0,0, //center
	//	1, // radius
	//	(int)WHITE, 
	//};

	/*Sphere sphere2
	{
		1.6f, 0,0,
		0.3f,
		(int)WHITE
	};*/

	/*Plane plane
	{
		0.0f,1.0f,0.0f,
		1.0f
	};*/

	Vector3 cameraRotate{ 0.26f, 0.0f, 0.0f };
	Vector3 cameraTranslate{ 0.0f,1.9f, -6.49f };
	Vector3 cameraPosition = { 0,0,-10.0f };

	Segment segment
	{
		{-0.7f, 0.3f, 0.0f}, //origin
		{2.0f, -0.5f, 0.0f}, //diff

	};
	//
	//Triangle triangle
	//{
	//	{0.0f,1.0f,0.0f,
	//	1.0f,-1.0f,0.0f,
	//	-1.0f,-1.0f,0.0f},
	//	(int)WHITE
	//};

	//Vector3 point{ -1.5f, 0.6f, 0.6f };

	AABB aabb1{
		.min{-0.5f, -0.5f, -0.5f},
		.max{0.5f, 0.5f, 0.5f}
	};

	int color = WHITE;

	//AABB aabb2{
	//	.min{0.2f, 0.2f, 0.2f},
	//	.max{1.0f, 1.0f, 1.0f},
	//	.color{(int)WHITE}
	//};

	Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f, 1.0f,1.0f }, { 0,0,0 }, { 0,0,0 });
	Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
	Matrix4x4 viewMatrix = Inverse(cameraMatrix);
	Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.f);
	Matrix4x4 viewMatrixProjectionMatrix = Multiply(viewMatrix, projectionMatrix);
	Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, viewMatrixProjectionMatrix);
	Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
	Vector3 start = Transform(Transform(segment.origin, viewMatrixProjectionMatrix), viewportMatrix);
	Vector3 end = Transform(Transform(Add(segment.origin, segment.diff), viewMatrixProjectionMatrix), viewportMatrix);

	void Initialize();

	void Updata();

	void Draw();
};

