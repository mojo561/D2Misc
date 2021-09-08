static dump1(dwModCode, dwModParam, dwModMin, dwModMax)
{
    if(dwModCode < 0xFFFFFFFF)
    {
        Message("0x%X::", dwModCode);
    }
    else if (dwModCode == 0xFFFFFFFF)
    {
        return;
    }
    if(dwModParam < 0xFFFFFFFF)
    {
        Message("(%d)", dwModParam);
    }
    else
    {
        Message("(%d)", 0xFFFFFFFF - (dwModParam+1));
    }
    if(dwModMin == dwModMax)
    {
        Message("[%d]", (dwModMin < 0xFFFFFFFF ? dwModMin : 0xFFFFFFFF - (dwModMin+1)));
    }
    else
    {
        Message("[%d.", (dwModMin < 0xFFFFFFFF ? dwModMin : 0xFFFFFFFF - (dwModMin+1)));
        Message("%d]", (dwModMax < 0xFFFFFFFF ? dwModMax : 0xFFFFFFFF - dwModMax+1));
    }
}

static dump2(WType)
{
	if(WType > 0x0)
		Message("0x%X", WType);
}

static main()
{
    auto d2commonbase = 0x6FD50000;
    auto ptrAffixTable = Dword(d2commonbase + 0x9FBC0);
    auto nAffixTableLen = Dword(d2commonbase + 0x9FBB8);
    auto i;
    auto j;
    
    Message("Row#,Name,dwGroup,wTableIndex,Mod1,Mod2,Mod3,wIType1,wIType2,wIType3,wIType4,wIType5,wIType6,wIType7,wEType1,wEType2,wEType3,wEType4,wEType5\n");
    for(i = 0; i < nAffixTableLen; ++i)
    {
		auto nextIndex = (0x90 * i);
		auto ptrNextRecord = ptrAffixTable + nextIndex;
		auto wTableIndex = Word(ptrNextRecord + 32);
		auto dwMod1Code = Dword(ptrNextRecord + 0x24);
		auto dwMod1Param = Dword(ptrNextRecord + 0x28);
		auto dwMod1Min = Dword(ptrNextRecord + 0x2C);
		auto dwMod1Max = Dword(ptrNextRecord + 0x30);
		auto dwMod2Code = Dword(ptrNextRecord + 0x34);
		auto dwMod2Param = Dword(ptrNextRecord + 0x38);
		auto dwMod2Min = Dword(ptrNextRecord + 0x3C);
		auto dwMod2Max = Dword(ptrNextRecord + 0x40);
		auto dwMod3Code = Dword(ptrNextRecord + 0x44);
		auto dwMod3Param = Dword(ptrNextRecord + 0x48);
		auto dwMod3Min = Dword(ptrNextRecord + 0x4C);
		auto dwMod3Max = Dword(ptrNextRecord + 0x50);
		auto dwGroup = Dword(ptrNextRecord + 0x5C);	
		auto wIType1 = Word(ptrNextRecord + 0x6A);//0x6A
		auto wIType2 = Word(ptrNextRecord + 0x6C);//0x6C
		auto wIType3 = Word(ptrNextRecord + 0x6E);//0x6E
		auto wIType4 = Word(ptrNextRecord + 0x70);//0x70
		auto wIType5 = Word(ptrNextRecord + 0x72);//0x72
		auto wIType6 = Word(ptrNextRecord + 0x74);//0x74
		auto wIType7 = Word(ptrNextRecord + 0x76);//0x76
		auto wEType1 = Word(ptrNextRecord + 0x78);//0x78
		auto wEType2 = Word(ptrNextRecord + 0x7A);//0x7A
		auto wEType3 = Word(ptrNextRecord + 0x7C);//0x7C
		auto wEType4 = Word(ptrNextRecord + 0x7E);//0x7E
		auto wEType5 = Word(ptrNextRecord + 0x80);//0x80
    	
        auto szName = ptrNextRecord;
        auto bNext = Byte(szName);
    	
        if(dwGroup == 0)
            continue;
    
        Message("%d,'", nextIndex / 0x90);
        for(j = 0; j < 32; ++j)
        {
            bNext = Byte(szName + j);
            if(bNext == 0)
                break;
            Message("%c", bNext);
        }
        Message("',0x%X,0x%X,", dwGroup, wTableIndex);
        
        
        dump1(dwMod1Code, dwMod1Param, dwMod1Min, dwMod1Max);
        Message(",");
        dump1(dwMod2Code, dwMod2Param, dwMod2Min, dwMod2Max);
        Message(",");
        dump1(dwMod3Code, dwMod3Param, dwMod3Min, dwMod3Max);
        
        Message(",");
        dump2(wIType1);
		Message(",");
		dump2(wIType2);
		Message(",");
		dump2(wIType3);
		Message(",");
		dump2(wIType4);
		Message(",");
		dump2(wIType5);
		Message(",");
		dump2(wIType6);
		Message(",");
		dump2(wIType7);
		Message(",");
		dump2(wEType1);
		Message(",");
		dump2(wEType2);
		Message(",");
		dump2(wEType3);
		Message(",");
		dump2(wEType4);
		Message(",");
		dump2(wEType5);
		Message("\n");
    }
}