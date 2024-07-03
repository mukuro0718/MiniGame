#include "Common.h"

JsonManager* JsonManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
JsonManager::JsonManager()
{
	LoadJsonFile();
}

/// <summary>
/// デストラクタ
/// </summary>
JsonManager::~JsonManager()
{

}

/// <summary>
/// jsonファイルの読み込み
/// </summary>
void JsonManager::LoadJsonFile()
{
	/*json読み込みクラスのインスタンスを取得*/
	auto& loader = JsonLoader::GetInstance();

	/*ファイルの名前を保持しているJsonファイルを読み込む*/
	this->baseJson = loader.GetJsonData("Data/Json/LoadJsonFile.json");

	/*読み込んだファイルのデータを保持*/
	std::vector<std::string> fileName = this->baseJson["FILE_NAME"];

	/*保持したデータの要素分だけループを回す*/
	for (int i = 0; i < fileName.size(); i++)
	{
		//対応するファイル名のjsonを読み込み、保持する
		this->json.push_back(loader.GetJsonData(fileName[i]));
	}
}