#pragma once
#include "AbstractSceneFactory.h"

/// <summary>
/// このゲーム用のシーン工場
/// </summary>
class SceneFactory : public AbstractSceneFactory
{
public: // メンバ関数
	/// <summary>
	/// シーン生成
	/// </summary>
	/// <param name="sceneName">シーン名</param>
	/// <returns>生成したシーン</returns>
	BaseScene* CreateScene(const std::string& sceneName) override;
};