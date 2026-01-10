class CfgPatches
{
  class LoadingScreens
  {
    units[]={};
    weapons[]={};
    requiredVersion=0.1;
    requiredAddons[]={ "DZ_Scripts" };
  };
};

class CfgMods
{
  class LoadingScreens
  {
    dir="LoadingScreens";
    hideName=0;
    hidePicture=0;
    extra=0;
    name="LoadingScreens";
    picture="LoadingScreens/data/picture.paa";
    logoSmall="LoadingScreens/data/logoSmall.paa";
    logo="LoadingScreens/data/logo.paa";
    logoOver="LoadingScreens/data/logo.paa";
    action="https://steamcommunity.com/sharedfiles/filedetails/?id=3643948795";
    credits="moldypenguins";
    author="moldypenguins";
    authorID="76561198312711389";
    version="1.0";
    type="mod";
    dependencies[]={ "Game" };
    class defs
    {
      class engineScriptModule
      {
        value="";
        files[]={ "LoadingScreens/scripts/1_core" };
      };
      class gameScriptModule
      {
        value="";
        files[]={ "LoadingScreens/scripts/3_game" };
      };
    }
  };
};
