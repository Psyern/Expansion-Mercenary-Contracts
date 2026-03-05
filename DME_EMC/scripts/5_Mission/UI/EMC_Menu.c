class EMC_Menu : UIScriptedMenu
{
	protected Widget m_Root;
	protected WrapSpacerWidget m_List;
	protected ref array<ref EMC_EntryWidget> m_Widgets;
	protected ref EMC_Config m_Config;

	void EMC_Menu()
	{
		m_Widgets = new array<ref EMC_EntryWidget>();
	}

	override Widget Init()
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets("ExpansionMercenaryContracts/gui/layouts/EMC_Menu.layout");
		m_List = WrapSpacerWidget.Cast(m_Root.FindAnyWidget("MercList"));
		Rebuild();
		return m_Root;
	}

	void SetConfig(EMC_Config config)
	{
		m_Config = config;
		Rebuild();
	}

	protected void Rebuild()
	{
		if (!m_Root || !m_List || !m_Config || !m_Config.Mercenaries)
			return;

		m_List.DeleteChildren();
		m_Widgets.Clear();

		for (int i = 0; i < m_Config.Mercenaries.Count(); i++)
		{
			Widget row = GetGame().GetWorkspace().CreateWidgets("ExpansionMercenaryContracts/gui/layouts/EMC_EntryWidget.layout", m_List);
			EMC_EntryWidget entry = new EMC_EntryWidget(row);
			entry.Bind(m_Config.Mercenaries.Get(i), i);
			m_Widgets.Insert(entry);
		}
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		for (int i = 0; i < m_Widgets.Count(); i++)
		{
			if (m_Widgets.Get(i).HandleClick(w))
				return true;
		}

		return super.OnClick(w, x, y, button);
	}
};
