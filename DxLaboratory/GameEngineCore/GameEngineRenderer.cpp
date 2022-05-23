#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

GameEngineRenderer::GameEngineRenderer() 
{
}

GameEngineRenderer::~GameEngineRenderer() 
{
}

void GameEngineRenderer::Start() 
{
	GetActor()->GetLevel()->PushRenderer(this);
}

float acc = 0;

void GameEngineRenderer::Render(float _DeltaTime)
{
	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("Hexagram");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("Hexagram");
	
	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());

	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());

	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		CopyBuffer[i] = Vertex->Vertexs[i];

		// 크기
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();

		// 자전
		CopyBuffer[i] = float4::VectorRotationToRadianZ(CopyBuffer[i], (GameEngineMath::PIE * 20.f) * _DeltaTime);

		// 이동
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();

		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}
	
	for (size_t i = 0; i < DrawVertex.size(); i += 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}
}