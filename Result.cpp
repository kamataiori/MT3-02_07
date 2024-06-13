#include "Result.h"

void Result::Initialize()
{
	cameraTranslate = { 0.0f,1.9f,-6.49f };
	cameraRotate = { 0.26f,0.0f,0.0f };
	rotate = {};
	translate = {};
	worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
	cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
	viewMatrix = Inverse(cameraMatrix);
	projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
	worldviewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

	segment1 = { {-2.0f,-1.0f,0.0f},{3.0f,2.0f,2.0f} };

	aabb = { .min{-0.5f,-0.5f,-0.5f},.max{0.5f,0.5f,0.5f}, };
}

void Result::Updata()
{

}

void Result::Draw()
{
	DrawAABB(aabb, worldviewProjectionMatrix, viewportMatrix, WHITE);
	//線分の描画
	Vector3 start = Transform(Transform(segment1.origin, worldviewProjectionMatrix), viewportMatrix);
	Vector3 end = Transform(Transform(Add(segment1.origin, segment1.diff), viewportMatrix), viewportMatrix);
	Novice::DrawLine(int(start.x), int(start.y), int(end.x), int(end.y), WHITE);
}
