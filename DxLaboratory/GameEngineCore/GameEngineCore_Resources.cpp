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
	// 사각형 박스 에러용 텍스처 등등
	// 엔진수준에서 기본적으로 지원줘야 한다고 생각하는
	// 리소스들을 이니셜라이즈하는 단계


	{
		// 0       1

		//    원점
		
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
		// 정삼각형
		Vertex.push_back(float4(0.f, 1.f));
		Vertex.push_back(float4(0.5f, -0.5f));
		Vertex.push_back(float4(-0.5f, -0.5f));

		// 역 정삼각형 -> x축 대칭(y 성분 부호만 반대로)
		Vertex.push_back(float4(0.f, -1.f));
		Vertex.push_back(float4(0.5f, +0.5f));
		Vertex.push_back(float4(-0.5f, +0.5f));

		GameEngineVertexBuffer::Create("Hexagram", Vertex);
	}

	{
		// 0       1

		//    원점

		// 3       2

		std::vector<int> Index;

		// 첫번째 삼각형
		// 디폴트 생성자로 인자를 뒤에 추가해주는 요소 추가 함수.
		Index.resize(6);

		// 첫번째
		Index[0] = 0;
		Index[1] = 1;
		Index[2] = 2;

		// 두번째
		Index[3] = 0;
		Index[4] = 2;
		Index[5] = 3;

		GameEngineIndexBuffer::Create("Rect", Index);
	}
	{
		std::vector<int> Index;

		Index.resize(6);

		// 정삼각형
		Index[0] = 0;
		Index[1] = 1;
		Index[2] = 2;

		// 역 정삼각형
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