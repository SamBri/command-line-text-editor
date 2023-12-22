        CLET EDITOR v1.0 MANUAL 

 

        ******************************* 

        Create (C) is a single command. 

        **********************************  

        ********************************  

        Edit(E) has subcommands tree. 

        1. E,I -> Insert Text, 

        2. E,D -> Delete Text 

        3. E,P -> Copy and Paste 

        4. E,F -> Find and replace 


        Each Edit subcommand may or may not have tree 


         1. E,I -> Insert Text 

        (E,I) : L -> line insertion 

        (E,I,L) : U -> line insertion on top of lineNumber 

        (E,I,L) : D -> line insertion below lineNumber. 

        (E,I,L,U) : lineNumber -> text to insert at line number 

        (E,I,L,D) : lineNumber -> text to insert at line number 


         2. E,D -> Delete Text 

        (E,D) : lineNumber -> text to delete on that lineNumber 


        3. E,P -> Copy and Paste 

        (E,P) : [srcCpy, destCpy, destPaste ] -> copy and paste text below the target paste line 

        4. E,F -> Find and replace 

        (E,F) : [searchText, replaceText] -> find searchText and replace with replaceText 

        *************************************************** 

        ************************************************** 

        Read (R) has subcommands. 

        1. (R, L) -> read with linenumber 

        2. (R,N)  -> read with no lineNumber. 

        ************************************************ 

        ******* Other Commands ************************* 

        2. Scroll with (Y) on lines more than 50 

        *************************************************** 
