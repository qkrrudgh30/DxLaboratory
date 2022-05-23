#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include "GameEngineLevel.h"

// Resources Header
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

void GameEngineCore::EngineResourcesInitialize()
{
	// �簢�� �ڽ� ������ �ؽ�ó ���
	// �������ؿ��� �⺻������ ������� �Ѵٰ� �����ϴ�
	// ���ҽ����� �̴ϼȶ������ϴ� �ܰ�


	{
		// 0       1

		//    ����
		
		// 3       2

		std::vector<float4> Vertex;
		Vertex.push_back(float4(-0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, -0.5f));
		Vertex.push_back(float4(-0.5f, -0.5f));

		GameEngineVertexBuffer::Create("Rect", Vertex);

	}
	{
		std::vector<float4> Vertex;
		// ���ﰢ��
		Vertex.push_back(float4(0.f, 1.f));
		Vertex.push_back(float4(0.5f, -0.5f));
		Vertex.push_back(float4(-0.5f, -0.5f));

		// �� ���ﰢ�� -> x�� ��Ī(y ���� ��ȣ�� �ݴ��)
		Vertex.push_back(float4(0.f, -1.f));
		Vertex.push_back(float4(0.5f, +0.5f));
		Vertex.push_back(float4(-0.5f, +0.5f));

		GameEngineVertexBuffer::Create("Hexagram", Vertex);
	}

	{
		// 0       1

		//    ����

		// 3       2

		std::vector<int> Index;

		// ù��° �ﰢ��
		// ����Ʈ �����ڷ� ���ڸ� �ڿ� �߰����ִ� ��� �߰� �Լ�.
		Index.resize(6);

		// ù��°
		Index[0] = 0;
		Index[1] = 1;
		Index[2] = 2;

		// �ι�°
		Index[3] = 0;
		Index[4] = 2;
		Index[5] = 3;

		GameEngineIndexBuffer::Create("Rect", Index);
	}
	{
		std::vector<int> Index;

		Index.resize(6);

		// ���ﰢ��
		Index[0] = 0;
		Index[1] = 1;
		Index[2] = 2;

		// �� ���ﰢ��
		Index[3] = 3;
		Index[4] = 4;
		Index[5] = 5;

		GameEngineIndexBuffer::Create("Hexagram", Index);
	}


}


void GameEngineCore::EngineResourcesDestroy()
{
	GameEngineVertexBuffer::ResourcesDestroy();
	GameEngineIndexBuffer::ResourcesDestroy();
}