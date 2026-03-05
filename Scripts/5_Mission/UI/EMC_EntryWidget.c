class EMC_EntryWidget
{
	protected Widget m_Root;
	protected TextWidget m_Label;
	protected ButtonWidget m_HireButton;
	protected int m_Index;

	void EMC_EntryWidget(Widget root)
	{
		m_Root = root;
		m_Label = TextWidget.Cast(root.FindAnyWidget("MercLabel"));
		m_HireButton = ButtonWidget.Cast(root.FindAnyWidget("HireButton"));
	}

	void Bind(EMC_MercenaryEntry entry, int index)
	{
		m_Index = index;
		if (m_Label)
			m_Label.SetText(string.Format("%1 | Cost: %2 | Cooldown: %3s", entry.Loadout, entry.Cost, entry.Cooldown));
	}

	bool HandleClick(Widget w)
	{
		if (w != m_HireButton)
			return false;

		autoptr ScriptRPC rpc = new ScriptRPC();
		rpc.Write(m_Index);
		rpc.Send(GetGame().GetPlayer(), EMC_RPC.REQUEST_HIRE, true, null);
		return true;
	}
};
