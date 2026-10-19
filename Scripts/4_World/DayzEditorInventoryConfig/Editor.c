class EditorInventoryConfig
{
	string head;
	string torso;
	string legs;
	string feet;
	string belt;
	string backpack;
	string inventory;
	string hands;
	string magazine;
}

modded class Editor
{
	static const string INVENTORY_CONFIG_FILE = "$saves:Editor/Missions/InventoryConfig.json";
	static const string INVENTORY_CONFIG_TEMPLATE = "DayzEditorInventoryConfig/Config/InventoryConfig.json";

	static EditorInventoryConfig LoadInventoryConfig()
	{
		if (!FileExist(INVENTORY_CONFIG_FILE))
			CopyFile(INVENTORY_CONFIG_TEMPLATE, INVENTORY_CONFIG_FILE);

		EditorInventoryConfig config = new EditorInventoryConfig();
		string error;
		JsonFileLoader<EditorInventoryConfig>.LoadFile(INVENTORY_CONFIG_FILE, config, error);

		return config;
	}

	override static PlayerBase CreateDefaultCharacter(string type, vector position, PlayerIdentity identity = null)
	{
		EditorLog.Trace("Editor::CreateDefaultCharacter");
		if (GetGame().GetPlayer()) {
			return PlayerBase.Cast(GetGame().GetPlayer());
		} 

		position[1] = GetGame().SurfaceY(position[0], position[2]);
		PlayerBase player = PlayerBase.Cast(GetGame().CreatePlayer(identity, type, position, 0, string.Empty));
		if (!player) {
			EditorLog.Error("Failed to create new player, type %1", type);
			return null;
		}

		player.SetPosition(position);
		player.Update();

		EditorInventoryConfig config = LoadInventoryConfig();

		if (config.head != string.Empty)
			player.GetInventory().CreateInInventory(config.head);
		if (config.torso != string.Empty)
			player.GetInventory().CreateInInventory(config.torso);
		if (config.legs != string.Empty)
			player.GetInventory().CreateInInventory(config.legs);
		if (config.feet != string.Empty)
			player.GetInventory().CreateInInventory(config.feet);
		if (config.belt != string.Empty)
			player.GetInventory().CreateInInventory(config.belt);
		if (config.backpack != string.Empty)
			player.GetInventory().CreateInInventory(config.backpack);

		if (config.inventory != string.Empty)
			player.GetInventory().CreateInInventory(config.inventory);

		if (config.hands != string.Empty)
		{
			EntityAI hands = player.GetHumanInventory().CreateInHands(config.hands);
			if (hands && config.magazine != string.Empty)
				hands.GetInventory().CreateAttachment(config.magazine);
		}

		return player;
	}
};
