// Fisher-Yates shuffle for Enforce Script
void ShuffleArray(array<string> arr)
{
  Math.Randomize(-1);
  for (int i=arr.Count() - 1; i > 0; i--)
  {
    int j=Math.RandomInt(0, i + 1);
    string temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }
}

modded class LoadingScreen
{
  private ref array<string> m_LoadScreenImages=
  {
    "{066E89212856E322}ScreenZ/gui/textures/loading_screens/loading_screen_1_co.edds",
    "{0870CD6915A1ECF8}ScreenZ/gui/textures/loading_screens/loading_screen_2_co.edds",
    "{0D850EAEFEF3164E}ScreenZ/gui/textures/loading_screens/loading_screen_3_co.edds",
    "{144C45F96E4FF34C}ScreenZ/gui/textures/loading_screens/loading_screen_4_co.edds"
  };

  private string m_LoadScreenMask="{EAF8A716BB515212}ScreenZ/gui/textures/loading_screens/loading_screen_mask.edds";

  string LoginScreenImage()
  {
    return "{0D704C4D21687199}ScreenZ/gui/textures/loading_screens/loading_screen_co.edds";
  }

  private int m_LastLoadScreen = -1;

	void LoadingScreen(DayZGame game)
	{
    m_ImageBackground.LoadMaskTexture(m_LoadScreenMask);
    ShuffleArray(m_LoadScreenImages);
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
    if (m_LastLoadScreen > m_LoadScreenImages.Count())
    {
      m_LastLoadScreen=0;
    }
    else
    {
      m_LastLoadScreen++;
    }
    m_ImageBackground.LoadImageFile(0, m_LoadScreenImages[m_LastLoadScreen]);
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
    image.LoadImageFile(0, g_Game.m_loading.LoginScreenImage());
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
    image.LoadImageFile(0, g_Game.m_loading.LoginScreenImage());
		return root;
	}
};
