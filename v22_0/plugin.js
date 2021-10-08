console.log("Loading v22 HelloWSMAddIn")

window.HelloWSMAddIn = window.HelloWSMAddIn || {};

window.HelloWSMAddIn.CreateBlock = function(nHistoryID, pt1, pt2) {
    args = {
        TestAPI: "HelloWSMAddIn.CreateBlock",
        nHistoryID: nHistoryID,
        pt1: pt1,
        pt2: pt2
    };
    return callAsyncAPI(args);
};

const createBlock = async (w,l,h) => {
    const pt1 = await WSM.Geom.Point3d(0,0,0);
    const pt2 = await WSM.Geom.Point3d(w,l,h);
    const histID = await FormIt.GroupEdit.GetEditingHistoryID();
    console.log(histID, pt1, pt2)

    const test = await HelloWSMAddIn.CreateBlock(histID, pt1, pt2);
}

document.getElementById("CreateBlockBtn").addEventListener("click", () => {
    const w = Number(document.getElementById("Width").value);
    const h = Number(document.getElementById("Height").value);
    const l = Number(document.getElementById("Length").value);

    createBlock(w,l,h);
});