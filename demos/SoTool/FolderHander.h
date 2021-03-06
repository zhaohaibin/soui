#pragma once

#include "droptarget.h"

class CFolderHander : public IFileDropHandler
{
    struct LANGEXTS
    {
        SStringW strLang;
        SStringW strExts;
    };

public:
    CFolderHander(void);
    ~CFolderHander(void);

    void OnInit(SWindow *pFolderRoot);
    void InitDir(const SStringW & strPath,BOOL bInput=FALSE);
protected:
    virtual void OnFileDropdown(HDROP hDrop);

    void OnBtnFileTypes(EventArgs *pEvt);
    void OnDirEnterFinish(EventArgs *pEvt);
    
    void InitLang(pugi::xml_node xmlNode);
    void InitDirTree(HSTREEITEM hTreeItem,const SStringW & strPath);

    EVENT_MAP_BEGIN()
        EVENT_NAME_HANDLER(L"btn_dropdown_filetypes",EventCmd::EventID, OnBtnFileTypes)
        EVENT_NAME_HANDLER(L"edit_dir",EventKeyEnter::EventID,OnDirEnterFinish)
    EVENT_MAP_BREAK()

    SWindow *   m_pFolderRoot;
    SStringW    m_strDir;
    STreeCtrl * m_pDirTree;

protected:

    typedef SArray<LANGEXTS> LANGEXTLIST;
    LANGEXTLIST m_lstLangExts;
};
