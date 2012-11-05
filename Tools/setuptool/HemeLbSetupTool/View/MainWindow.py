# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

import wx

from HemeLbSetupTool.View.ToolPanel import ToolPanel
from HemeLbSetupTool.View.VtkViewPanel import VtkViewPanel


class MainWindow(wx.Frame):
    def __init__(self, controller):
        wx.Frame.__init__(self, None, title="HemeLB Setup Tool")
        self.appController = controller
        
        # self._InitMenu()
        #self._InitStatusBar() # A Statusbar in the bottom of the window
        
        # Going to have a vertically split window; tools on the left,
        # render window on the right.
        self.splitter = wx.SplitterWindow(self)
        
        self.toolPanel = ToolPanel(controller, self.splitter)
        self.vtkPanel = VtkViewPanel(controller.Pipeline, self.splitter)
        self.splitter.SplitVertically(self.toolPanel, self.vtkPanel)
        
        self.Show(True)
        
        return
    
    def _InitMenu(self):
        """Do stuff for the menu.
        """
        filemenu = wx.Menu()
        
        # wx.ID_ABOUT and wx.ID_EXIT are standard IDs provided by wxWidgets.
        filemenu.Append(wx.ID_ABOUT, "&About"," Information about this program")
        filemenu.AppendSeparator()
        filemenu.Append(wx.ID_EXIT,"E&xit"," Terminate the program")
        
        # Creating the menubar.
        menuBar = wx.MenuBar()
        menuBar.Append(filemenu,"&File") # Adding the "filemenu" to the MenuBar
        self.SetMenuBar(menuBar)  # Adding the MenuBar to the Frame content.

        return
     

    pass
