int tableWidth = 73;

void Main(string[] args)
{
    Console.Clear();
    PrintLine();
    PrintRow("Column 1", "Column 2", "Column 3", "Column 4");
    PrintLine();
    PrintRow("", "", "", "");
    PrintRow("", "", "", "");
    PrintLine();
    Console.ReadLine();
}

void PrintLine()
{
    Console.WriteLine(new string('-', tableWidth));
}

void PrintRow(params string[] columns)
{
    int width = (tableWidth - columns.Length) / columns.Length;
    string row = "|";

    foreach (string column in columns)
    {
        row += AlignCentre(column, width) + "|";
    }

    Console.WriteLine(row);
}

char* AlignCentre(char* text, int width)
{
    text = text.Length > width ? text.Substring(0, width - 3) + "..." : text;

    if (string.IsNullOrEmpty(text))
    {
        return new string(' ', width);
    }
    else
    {
        return text.PadRight(width - (width - text.Length) / 2).PadLeft(width);
    }
}
