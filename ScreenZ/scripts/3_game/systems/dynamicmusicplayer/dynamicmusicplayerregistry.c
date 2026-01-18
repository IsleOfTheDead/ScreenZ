modded class DynamicMusicPlayerRegistry
{
	override protected void RegisterTracksMenu()
	{
		m_TracksMenu = new array<ref DynamicMusicTrackData>();

		// RegisterTrackMenu("Music_Menu_SoundSet", true);
		RegisterTrackMenu("ScreenZ_Menu_SoundSet", true);
	}
}
