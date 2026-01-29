/** @file dayzgame.c */

modded class LoadingScreen
{
  private int m_LastLoadScreen = -1;

	void LoadingScreen(DayZGame game)
	{
    m_ImageBackground.LoadMaskTexture(SCREENZ_LOAD_MASK);
    // Fisher-Yates shuffle for Enforce Script
    Math.Randomize(-1);
    for (int i=SCREENZ_LOAD_IMAGES.Count() - 1; i > 0; i--)
    {
      int j=Math.RandomInt(0, i + 1);
      string temp=SCREENZ_LOAD_IMAGES[i];
      SCREENZ_LOAD_IMAGES[i]=SCREENZ_LOAD_IMAGES[j];
      SCREENZ_LOAD_IMAGES[j]=temp;
    }
    NextLoadScreenImage();

		m_ModdedWarning.Show(false);
		m_ImageLogoMid.Show(false);
		m_ImageLogoCorner.Show(true);
		m_ImageWidgetBackground.Show(true);
		m_Counter=0;

		// lighten up your desktop
		game.GetBacklit().LoadingAnim();
		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
	}

  void NextLoadScreenImage()
  {
    if (m_LastLoadScreen > SCREENZ_LOAD_IMAGES.Count())
    {
      m_LastLoadScreen=0;
    }
    else
    {
      m_LastLoadScreen++;
    }
    m_ImageBackground.LoadImageFile(0, SCREENZ_LOAD_IMAGES[m_LastLoadScreen]);
  }

};

modded class LoginTimeBase
{
	void LoginTimeBase()
  {
    g_Game.m_loading.NextLoadScreenImage();
  }
	override Widget Init()
	{
    Widget root=super.Init();
		ImageWidget image=ImageWidget.Cast(root.FindAnyWidget("Background"));
    image.LoadImageFile(0, SCREENZ_LOGIN_IMAGE);
		return root;
	}
};

modded class LoginQueueBase
{
	void LoginQueueBase()
  {
    g_Game.m_loading.NextLoadScreenImage();
  }
	override Widget Init()
	{
    Widget root=super.Init();
		ImageWidget image=ImageWidget.Cast(root.FindAnyWidget("Background"));
    image.LoadImageFile(0, SCREENZ_LOGIN_IMAGE);
		return root;
	}
};
