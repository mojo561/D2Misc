static dumpUnitDetails(ptrUnit)
{
    auto dwUnitType = Dword(ptrUnit);
    auto dwLineClassId = Dword(ptrUnit + 4);
    auto dwUnitId = Dword(ptrUnit + 0xC);
    auto ptrData = Dword(ptrUnit + 0x14);
    auto ptrInventory = Dword(ptrUnit + 0x60);
    auto dwDropItemCode = Dword(ptrUnit + 0xB8);
    auto dwClientId = Dword(ptrUnit + 0xD0);
    auto unitTypeStr = "ptrUnitPlayer";
    Message("==================================\n");
    if (dwUnitType == 0x1) unitTypeStr = "ptrUnitMonster";
    else if (dwUnitType == 0x2) unitTypeStr = "ptrUnitObject";
    else if (dwUnitType == 0x3) unitTypeStr = "ptrUnitMissle";
    else if (dwUnitType == 0x4) unitTypeStr = "ptrUnitItem";
    //0x5 (tile): unused?
    Message("%s (%Xh)\n", unitTypeStr, ptrUnit);
    
    Message("dwUnitType (+0): 0x%X\n", dwUnitType);
    Message("dwLineId or dwClassId (+4): 0x%X\n", dwLineClassId);
    Message("dwUnitId (+0xC): %d\n", dwUnitId);
    Message("ptrData (+0x14): %Xh\n", ptrData);
    Message("ptrInventory (+0x60): %Xh\n", ptrInventory);
    Message("dwDropItemCode (+0xB8): 0x%X\n", dwDropItemCode);
    Message("dwClientId (+0xD0): 0x%X\n", dwClientId);
    return;
}

static dumpInventoryDetails(ptrInventory)
{
    auto dwTag = Dword(ptrInventory + 0x00);
    auto ptrMemPool = Dword(ptrInventory + 0x04);
    auto ptrOwner = Dword(ptrInventory + 0x08);
    auto ptrFirstItem = Dword(ptrInventory + 0x0C);
    auto ptrLastItem = Dword(ptrInventory + 0x10);
    auto ptrInvInfo = Dword(ptrInventory + 0x14);
    auto nInvInfo = Dword(ptrInventory + 0x18);
    auto dwLeftItemGUID = Dword(ptrInventory + 0x1C);
    auto ptrCursorItem = Dword(ptrInventory + 0x20);
    auto dwOwnerId = Dword(ptrInventory + 0x24);
    auto dwItemCount = Dword(ptrInventory + 0x28);
    auto dwInventory2C = Dword(ptrInventory + 0x2C);
    auto dwInventory30 = Dword(ptrInventory + 0x30);
    auto ptrFirstCorpse = Dword(ptrInventory + 0x34);
    auto dwNextCorpseId = Dword(ptrInventory + 0x3C);
    
    Message("==================================\n");
    Message("ptrInventory (%Xh)\n", ptrInventory);
    Message("dwTag (+0x00): %d\n", dwTag);
    Message("ptrMemPool (+0x04): %Xh\n", ptrMemPool);
    Message("ptrOwner (+0x08): %Xh\n", ptrOwner);
    Message("ptrFirstItem (+0x0C): %Xh\n", ptrFirstItem);
    Message("ptrLastItem (+0x10): %Xh\n", ptrLastItem);
    Message("ptrInvInfo (0x14): %Xh\n", ptrInvInfo);
    Message("nInvInfo (0x18): %d\n", nInvInfo);
    Message("dwLeftItemGUID (0x1C): %d\n", dwLeftItemGUID);
    Message("ptrCursorItem (+0x20): %Xh\n", ptrCursorItem);
    Message("dwOwnerId (0x24): %d\n", dwOwnerId);
    Message("dwItemCount (+0x28): %d\n", dwItemCount);
    Message("dwInventory2C (+0x2C): %d\n", dwInventory2C);
    Message("dwInventory30 (+0x30): %d\n", dwInventory30);
    Message("ptrFirstCorpse (+0x34): %Xh\n", ptrFirstCorpse);
    Message("dwNextCorpseId (+0x3C): %d\n", dwNextCorpseId);
    return;
}

static dumpItemData(ptrItemData)
{
    auto dwQualityNo = Dword(ptrItemData + 0x00);
    auto dwLowSeed = Dword(ptrItemData + 0x04);
    auto dwHighSeed = Dword(ptrItemData + 0x08);
    auto dwOwnerGUID = Dword(ptrItemData + 0x0C);
    auto dwInitSeed = Dword(ptrItemData + 0x10);
    auto dwCommandFlags = Dword(ptrItemData + 0x14);
    auto dwItemFlags = Dword(ptrItemData + 0x18);
    auto dwGuid1 = Dword(ptrItemData + 0x1C);
    auto dwGuid2 = Dword(ptrItemData + 0x20);
    auto dwActionStamp = Dword(ptrItemData + 0x24);
    auto dwUniqueID = Dword(ptrItemData + 0x28);
    auto dwItemLevel = Dword(ptrItemData + 0x2C);
    auto wItemFormat = Word(ptrItemData + 0x30);
    auto wRarePrefix = Word(ptrItemData + 0x32);
    auto wRareSuffix = Word(ptrItemData + 0x34);
    auto wAutoPrefix = Word(ptrItemData + 0x36);
    auto wMagicPrefix = Word(ptrItemData + 0x38);
    auto wMagicSuffix = Word(ptrItemData + 0x3E);
    auto bBodyLoc = Byte(ptrItemData + 0x44);
    auto bInvPage = Byte(ptrItemData + 0x45);
    auto bItemData3 = Byte(ptrItemData + 0x47);
    auto bEarLvl = Byte(ptrItemData + 0x48);
    auto bInvGfxIdx = Byte(ptrItemData + 0x49);
    auto IName = Byte(ptrItemData + 0x4A);
    auto ptrPrevItem = Dword(ptrItemData + 0x60);
    auto bNodePos = Byte(ptrItemData + 0x68);
    auto bNodePosOther = Byte(ptrItemData + 0x69);
    //auto ptrUnitOwner = Dword(ptrItemData + 0x84);
    auto i = 0;
    auto offset = 0;
    auto ptrInventory = Dword(ptrItemData + 0x5C);
    auto ptrNextItem = Dword(ptrItemData + 0x64);

    Message("==================================\n");
    Message("ptrItemData (%Xh)\n", ptrItemData);
    Message("dwQualityNo (+0x00): %d\n", dwQualityNo);
    Message("dwLowSeed (+0x04): %d\n", dwLowSeed);
    Message("dwHighSeed (+0x08): %d\n", dwHighSeed);
    Message("dwOwnerGUID (+0x0C): %d\n", dwOwnerGUID);
    Message("dwInitSeed (+0x10): %d\n", dwInitSeed);
    Message("dwCommandFlags (+0x14): "); print(dwCommandFlags);
    Message("dwItemFlags (+0x18): "); print(dwItemFlags);
    Message("dwGuid1 (+0x1C): %d\n", dwGuid1);
    Message("dwGuid2 (+0x20): %d\n", dwGuid2);
    Message("dwActionStamp (guid3?) (+0x24): %d\n", dwActionStamp);
    Message("dwUniqueID (+0x28): %d\n", dwUniqueID);
    Message("dwItemLevel (+0x2C): %d\n", dwItemLevel);
    Message("wItemFormat (version?) (+0x30): %d\n", wItemFormat);
    Message("wRarePrefix (+0x32): %d\n", wRarePrefix);
    Message("wRareSuffix (+0x34): %d\n", wRareSuffix);
    Message("wAutoPrefix (+0x36): %d\n", wAutoPrefix);

    Message("wMagicPrefix[0:3] => [");
    for(i = 0; i < 2; ++i)
    {
        offset = i * 2;
        Message("%X, ", Word(wMagicPrefix + offset));
    }
    Message("%X]\n", Word(wMagicSuffix - 2));
    
    Message("wMagicSuffix[0:3] => [");
    for(i = 0; i < 2; ++i)
    {
        offset = i * 2;
        Message("%X, ", Word(wMagicSuffix + offset));
    }
    Message("%X]\n", Word(bBodyLoc - 2));

    /*	location if equipped
	*	00 = noequip/inBelt
	*	01 = head
	*	02 = neck
	*	03 = tors
	*	04 = rarm
	*	05 = larm
	*	06 = lrin
	*	07 = rrin
	*	08 = belt
	*	09 = feet
	*	0A = glov
	*	0B = ralt
    	*	0C = lalt
    */
    auto locstr = "unknown...";
    if (bBodyLoc == 0x00) locstr = "noequip/inBelt";
    else if (bBodyLoc == 0x01) locstr = "head";
    else if (bBodyLoc == 0x02) locstr = "neck";
    else if (bBodyLoc == 0x03) locstr = "tors";
    else if (bBodyLoc == 0x04) locstr = "rarm";
    else if (bBodyLoc == 0x05) locstr = "larm";
    else if (bBodyLoc == 0x06) locstr = "lrin";
    else if (bBodyLoc == 0x07) locstr = "rrin";
    else if (bBodyLoc == 0x08) locstr = "belt";
    else if (bBodyLoc == 0x09) locstr = "feet";
    else if (bBodyLoc == 0x0A) locstr = "glov";
    else if (bBodyLoc == 0x0B) locstr = "ralt";
    else if (bBodyLoc == 0x0C) locstr = "lalt";
    Message("bBodyLoc (+0x44): %d (%s)\n", bBodyLoc, locstr);

    /*	page dans laquel se trouve l'item
    *	FF = mouse/equip/onEarth
    *	00 = inventory
    *   01 = cube
    *	04 = stash
    */
    auto invstr = "unknown...";
    if(bInvPage == 0xFF) invstr = "mouse/equip/onEarth";
    else if(bInvPage == 0) invstr = "inventory";
    else if(bInvPage == 1) invstr = "cube";
    else if(bInvPage == 4) invstr = "stash";
    Message("bInvPage (+0x45): %d (%s)\n", bInvPage, invstr);
    
    Message("bItemData3 (D2Common10854 D2Common10853) (+0x47): %X\n", bItemData3);
    Message("bEarLvl (+0x48): %d\n", bEarLvl);
    Message("bInvGfxIdx (+0x49): %d\n", bInvGfxIdx);

    for(i = 0; i < 0x12; ++i)
    {
        auto bnext = Byte(IName + i);
        if(bnext >= 0x20 && bnext <= 0x7E)
        {
            Message("IName[%d] (inscribed/ear name) (+0x%X): %c\n", i, 0x4A + i, bnext);
        }
    }

    Message("ptrInventory (+0x5C): %Xh\n", ptrInventory);
    Message("ptrPrevItem (+0x60): %Xh\n", ptrPrevItem);
    Message("ptrNextItem (+0x64): %Xh\n", ptrNextItem);
    Message("bNodePos (+0x68): %d\n", bNodePos);
    Message("bNodePosOther (ItemData2?) (+0x69): %d\n", bNodePosOther);
    //Message("ptrUnitOwner (+0x84): %Xh\n", Dword(ptrUnitOwner));
    return;
}

static main()
{
    auto ptrUnit = ptrUnitB;
    auto ptrInventory = Dword(ptrUnit + 0x60);
    auto ptrFirstItem = Dword(ptrInventory + 0x0C);
    auto ptrLastItem = Dword(ptrInventory + 0x10);
    auto ptrNextItem = ptrFirstItem;
    auto dwUnitType = 0;
    auto ptrItemData = 0;
    
    dumpUnitDetails(ptrUnit);
    dumpInventoryDetails(ptrInventory);
    
    do
    {
        ptrUnit = ptrNextItem;
        dwUnitType = Dword(ptrUnit);
        ptrItemData = Dword(ptrUnit + 0x14);
    
        dumpUnitDetails(ptrUnit);
        
        if(dwUnitType != 0x4)
        {
            break;
        }
        
        ptrNextItem = Dword(ptrItemData + 0x64);
        dumpItemData(ptrItemData);
        
    } while (ptrUnit != ptrLastItem);
}